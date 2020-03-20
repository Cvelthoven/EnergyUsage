//---------------------------------------------------------------------------------------
//
//  Class euDatabase
//
//  This class handles the data interaction with the underlying database
//
#include "energyusage.h"
#include "eudatabase.h"
#include "euapplicationlogging.h"
#include "euapplicationsettings.h"

#include <QMessageBox>
#include <QSqlDatabase>
#include <QtSql>
#include <QString>
#include <QStringList>

#include <QDebug>

//---------------------------------------------------------------------------------------
//
//  Constructor
//
euDatabase::euDatabase(QObject *parent, euApplicationLogging *ApplicationLog)
    : QStandardItemModel(parent)
{

    ApplicationSettings = new euApplicationSettings();
    euRetrieveConfig();
    if (euConnectDB(ApplicationLog,&strDatabaseName,&strDatabaseServerName,&strDatabaseUserId,&strDatabasePassword))
    {
        bDBconnected = true;
    }
    else
    {
        bDBconnected = false;
    }


}

//---------------------------------------------------------------------------------------
//
//  Database create, connect functions
//
//---------------------------------------------------------------------------------------
//
//  euConnectDB
//
//  Connects to the database and verifies that the tables exist or let them be created
//
bool euDatabase::euConnectDB(euApplicationLogging *ApplicationLog, QString *strDatabaseName, QString *strHostName, QString *strUserId, QString *strPassword)
{
    QString
            strSeverity,
            strLogMessage;
    QStringList
            stlDbDrivers;

    QMessageBox
        msgBox;

    //-----------------------------------------------------------------------------------
    //
    //  Load Postgresql driver
    //
    stlDbDrivers = QSqlDatabase::drivers();
    if (!stlDbDrivers.contains("QPSQL"))
    {
        strSeverity = "Error";
        strLogMessage = "No Postgresql driver found";
        ApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
        return false;
    }

    //-----------------------------------------------------------------------------------
    //
    //  Open database
    //
    sdbEnergyUsage = QSqlDatabase::addDatabase("QPSQL","EnergyUsage");
    sdbEnergyUsage.setHostName(*strHostName);
    sdbEnergyUsage.setDatabaseName(*strDatabaseName);
    sdbEnergyUsage.setPort(-1);
    if (!sdbEnergyUsage.open(*strUserId,*strPassword))
    {
        strSeverity = "Error";
        strLogMessage = "Unable to connect to database: " + *strDatabaseName;
        ApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
        return false;
    }
    else
    {
        strSeverity = "Info";
        strLogMessage = "Connected to database: " + *strDatabaseName;
        ApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);

    }

    //-----------------------------------------------------------------------------------
    //
    //  Check tables
    //
    stlDbTables = sdbEnergyUsage.tables();
    //
    //  Check eu_gas_usage table exists
    if (!stlDbTables.contains(strTblGasName))
    {
        if (!euGasCreateTable())
        {
            strSeverity = "Error";
            strLogMessage = "Table: " + strTblGasName + " not found and could not be created";
            ApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
            return false;
        }
    }

    return true;
}

//---------------------------------------------------------------------------------------
//
//  euGasCreateTable
//
//  Creates the table: strTblGasName
//
bool euDatabase::euGasCreateTable()
{
    QString
        strQuery;

    //-----------------------------------------------------------------------------------
    //
    //  Build build query of strTblGasName
    strQuery = "CREATE TABLE " + strTblGasName + " (";
    strQuery.append(strFldGasRecId + " SERIAL PRIMARY KEY, ");
    strQuery.append(strFldDateStart + " date, ");
    strQuery.append(strFldTimeStart + " time without time zone, ");
    strQuery.append(strFldDateEnd + " date, ");
    strQuery.append(strFldTimeEnd + " time without time zone, ");
    strQuery.append(strFldActualUsage + " numeric(10,4), ");
    strQuery.append(strFldExpectedUsage + " numeric(10,4), ");
    strQuery.append(strFldResult + " integer, ");
    strQuery.append(strFldDegreeDay + " numeric(8,4), ");
    strQuery.append(strFldPerDegreeDay + " numeric(8,4)");
    strQuery.append(");");


    //-----------------------------------------------------------------------------------
    //
    //  Create eu_gas_usage table
    //
    QSqlQuery qQuery("",sdbEnergyUsage);
    if (!qQuery.exec(strQuery))
    {
        qDebug() << sdbEnergyUsage.lastError();
        return false;
    }

    return true;
}

//---------------------------------------------------------------------------------------
//
//  euRetrieveConfig
//
//  Retrieves the database related application settings
//
bool euDatabase::euRetrieveConfig()
{
    bool
        bOK = true;

    int iStrlen;

    //-----------------------------------------------------------------------------------
    //
    //  Get datbase configuration
    strDatabaseServerName = ApplicationSettings->euGetAppSetting(strDatabaseSection, strKeyDbServerName);
    iStrlen = strDatabaseServerName.length();
    if (iStrlen == 0)
    {
        bOK = ApplicationSettings->euSetAppSetting(strDatabaseSection,strKeyDbServerName,strDatabaseServerNameDef);
        strDatabaseServerName = strDatabaseServerNameDef;
    }
    strDatabaseName = ApplicationSettings->euGetAppSetting(strDatabaseSection, strKeyDbName);
    iStrlen = strDatabaseName.length();
    if (iStrlen == 0)
    {
        bOK = ApplicationSettings->euSetAppSetting(strDatabaseSection,strKeyDbName,strDatabaseNameDef);
        strDatabaseName = strDatabaseNameDef;
    }
    strDatabaseUserId = ApplicationSettings->euGetAppSetting(strDatabaseSection, strKeyDbUserId);
    iStrlen = strDatabaseUserId.length();
    if (iStrlen == 0)
    {
        bOK = ApplicationSettings->euSetAppSetting(strDatabaseSection,strKeyDbUserId,strDatabaseUserIdDef);
        strDatabaseUserId = strDatabaseUserIdDef;
    }
    strDatabasePassword = ApplicationSettings->euGetAppSetting(strDatabaseSection, strKeyDbPassword);
    iStrlen = strDatabasePassword.length();
    if (iStrlen == 0)
    {
        bOK = ApplicationSettings->euSetAppSetting(strDatabaseSection,strKeyDbPassword,strDatabasePasswordDef);
        strDatabasePassword = strDatabasePasswordDef;
    }


    return(bOK);
}

//---------------------------------------------------------------------------------------
//
//  File import functions
//
//---------------------------------------------------------------------------------------
//
//  Add record
//
bool euDatabase::AddRecord(QStringList *stlInputValues)
{
    int
        iNbValues;  // Number of values in input stringlist

    QString
        strStartDate,
        strStartTime,
        strEndDate,
        strEndTime,
        strTemp;



    //-----------------------------------------------------------------------------------
    //
    //  Get number of values
    //
    iNbValues = stlInputValues->size();

    //-----------------------------------------------------------------------------------
    //
    //  Prepare query for Gas table
    //
    if ((stlInputValues->at(0) == "gas")&&(iNbValues == iGasValueNb))
    {
        //
        //  Convert timestamps input file to postgress format
        //
        strTemp = stlInputValues->at(1);
        ConvertTimeStamp(&strTemp,strStartDate,strStartTime);
        strTemp = stlInputValues->at(2);
        ConvertTimeStamp(&strTemp,strEndDate,strEndTime);

        //INSERT INTO application_log (apl_log_application_name, apl_log_time_stamp, apl_log_severity,apl_log_message) VALUES ('test','1/3/2019 12:38:00.123','info','Program started');
        // eu_gas_usage
//  database fields
//        eu_gas_date_start date,
//        eu_gas_time_start time without time zone,
//        eu_gas_date_end date,
//        eu_gas_time_end time without time zone,
//        eu_gas_actual_usage numeric(10,4),
//        eu_gas_expected_usage numeric(10,4),
//        eu_gas_result integer,
//        eu_gas_degree_day numeric(8,4),
//        eu_gas_per_degree_day numeric(8,4),

    }

    return true;
}

//---------------------------------------------------------------------------------------
//
//  Open import file
//
bool euDatabase::ExtractValuesForLine(QString *strMetricType, QString *strInputLine)
{
    int
        iInputStringLength,         // length of the input string
        iInputStringUsed    = 0,    // position in inputstring
        iValueCnt           = 0,
        iValueLength;               // length of the value string

    QString
        strTemp;

    //-----------------------------------------------------------------------------------
    //
    //  Set metric type in record list
    //
    stlRecordValues << *strMetricType;

    //-----------------------------------------------------------------------------------
    //
    //  extract sting values out of the inputline
    //
    iInputStringLength = strInputLine->size();
    while (iInputStringUsed < iInputStringLength)
    {
        strTemp = strInputLine->section((";"),iValueCnt,iValueCnt);
        stlRecordValues.append(strTemp);
        iValueLength = strTemp.size();
        iInputStringUsed += iValueLength +1;
        iValueCnt++;
    }
    return AddRecord(&stlRecordValues);

}

//---------------------------------------------------------------------------------------
//
//  Open import file
//
int euDatabase::ImportMetricsFile(QString *strMetricFileType, QString *strImportFileName)
{
    int iTotalLines = 0,
        iTotalRecords = 0;

    QString
        strInputLine;

    strMetricType = *strMetricFileType;

    //-----------------------------------------------------------------------------------
    //
    //  Open imput file
    //
    QFile qfiImportFile(*strImportFileName);
    if (qfiImportFile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        //-------------------------------------------------------------------------------
        //
        //  Process file line by line
        //
        QTextStream qtsImportFile(&qfiImportFile);
        //  read header line
        strInputLine = qtsImportFile.readLine();
        while (!qtsImportFile.atEnd())
        {
            strInputLine = qtsImportFile.readLine();
            iTotalRecords = ExtractValuesForLine(strMetricFileType,&strInputLine) + iTotalRecords;
            iTotalLines++;
        }
    }
    return(iTotalRecords);
}

//---------------------------------------------------------------------------------------
//
//  Convert timestmap format from yyyy-mm-dd hh:mm to (m)m/(d)d/yyyy (h)h:mm:00.000
//
void euDatabase::ConvertTimeStamp(QString *strTimeStampIn, QString &strDateOut, QString &strTimeOut)
{
    int
        iYear,
        iMonth,
        iDay,
        iHour,
        iMinute;

    QString
        strTemp;


    //-----------------------------------------------------------------------------------
    //
    //  Convert timestmap format from yyyy-mm-dd hh:mm to (m)m/(d)d/yyyy (h)h:mm:00.000
    //
    strTemp = *strTimeStampIn;
    strTemp.replace("-",":");
    strTemp.replace(" ",":");
    strTemp.replace(":0",":");
    iYear   = strTemp.section(":",0,0).toInt();
    iMonth  = strTemp.section(":",1,1).toInt();
    iDay    = strTemp.section(":",2,2).toInt();
    iHour   = strTemp.section(":",3,3).toInt();
    iMinute = strTemp.section(":",4,4).toInt();
    strTemp = QString("%1").arg(iMonth);
    strTemp.append("/");
    strTemp.append(QString("%1").arg(iDay));
    strTemp.append("/");
    strTemp.append(QString("%1").arg(iYear));
    strDateOut = strTemp;

    strTemp = QString("%1").arg(iHour);
    strTemp.append(":");
    strTemp.append(QString("%1").arg(iMinute,2,10,QChar('0')));
    strTemp.append(":00.000");
    strTimeOut = strTemp;

}
