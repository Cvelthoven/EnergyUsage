//---------------------------------------------------------------------------------------
//
//  Class euDatabase
//
//  This class handles the data interaction with the underlying database
//
#include "energyusage.h"
#include "energyusagedatabase.h"
#include "applicationlogging.h"
#include "applicationsettingsmodel.h"

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
EnergyUsageDatabase::EnergyUsageDatabase(QObject *parent, ApplicationLogging *ApplicationLog)
    : QStandardItemModel(parent)
{

    AppSettings = new ApplicationSettingsModel();
    dbApplicationLog = ApplicationLog;
    euRetrieveConfig();
    if (euConnectDB(&strDatabaseName,&strDatabaseServerName,&strDatabaseUserId,&strDatabasePassword))
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
//  Destructor with disconnect from metrics database
//
EnergyUsageDatabase::~EnergyUsageDatabase()
{
    sdbEnergyUsage.close();
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
bool EnergyUsageDatabase::euConnectDB(QString *strDatabaseName, QString *strHostName,
                             QString *strUserId, QString *strPassword)
{
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
        dbApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
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
        dbApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
        return false;
    }
    else
    {
        strSeverity = "Info";
        strLogMessage = "Connected to database: " + *strDatabaseName;
        dbApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
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
        if (CreateTable(&strTblGasName,&stlGasTableFieldNames,&stlGasTableFieldTypes))
        {
            strSeverity = "Info";
            strLogMessage = "Table: " + strTblGasName + " created";
            dbApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
        }
        else
        {
            strSeverity = "Error";
            strLogMessage = "Table: " + strTblGasName + " not found and could not be created";
            dbApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
            return false;
        }
    }

    //
    //  Check eu_elec_usage table exists
    if (!stlDbTables.contains(strTblElecName))
    {
        if (CreateTable(&strTblElecName,&stlElecTableFieldNames,&stlElecTableFieldTypes))
        {
            strSeverity = "Info";
            strLogMessage = "Table: " + strTblElecName + " created";
            dbApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
        }
        else
        {
            strSeverity = "Error";
            strLogMessage = "Table: " + strTblElecName + " not found and could not be created";
            dbApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
            return false;
        }
    }


    //
    //  Check eu_water_usage table exists
    if (!stlDbTables.contains(strTblWaterName))
    {
        if (CreateTable(&strTblWaterName,&stlWaterTableFieldNames,&stlWaterTableFieldTypes))
        {
            strSeverity = "Info";
            strLogMessage = "Table: " + strTblWaterName + " created";
            dbApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
        }
        else
        {
            strSeverity = "Error";
            strLogMessage = "Table: " + strTblWaterName + " not found and could not be created";
            dbApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
            return false;
        }
    }

    return true;
}

//---------------------------------------------------------------------------------------
//
//  CreateTable
//
//  Creates the tables
//
bool EnergyUsageDatabase::CreateTable(const QString *strTableName,
                             const QStringList *stlTableFieldNames,
                             const QStringList *stlTableFieldTypes)
{
    int
        iCnt;

    QString
        strQuery;

    //-----------------------------------------------------------------------------------
    //
    //  Build build table creation query
    strQuery = "CREATE TABLE " + *strTableName + " (";
    for (iCnt = 0; iCnt < stlTableFieldNames->size(); iCnt++)
    {
        strQuery.append(stlTableFieldNames->at(iCnt));
        strQuery.append(" ");
        strQuery.append(stlTableFieldTypes->at(iCnt));
        if (iCnt != (stlTableFieldNames->size() - 1))
            strQuery.append(", ");
        else
            strQuery.append(");");
    }

    //-----------------------------------------------------------------------------------
    //
    //  Create table
    //
    return ExecQuery(&strQuery);

}

//---------------------------------------------------------------------------------------
//
//  euRetrieveConfig
//
//  Retrieves the database related application settings
//
bool EnergyUsageDatabase::euRetrieveConfig()
{
    bool
        bOK = true;

    int iStrlen;

    //-----------------------------------------------------------------------------------
    //
    //  Get datbase configuration
    strDatabaseServerName = AppSettings->GetAppSetting(strDatabaseSection, strKeyDbServerName);
    iStrlen = strDatabaseServerName.length();
    if (iStrlen == 0)
    {
        bOK = AppSettings->SetAppSetting(strDatabaseSection,strKeyDbServerName,strDatabaseServerNameDef);
        strDatabaseServerName = strDatabaseServerNameDef;
    }
    strDatabaseName = AppSettings->GetAppSetting(strDatabaseSection, strKeyDbName);
    iStrlen = strDatabaseName.length();
    if (iStrlen == 0)
    {
        bOK = AppSettings->SetAppSetting(strDatabaseSection,strKeyDbName,strDatabaseNameDef);
        strDatabaseName = strDatabaseNameDef;
    }
    strDatabaseUserId = AppSettings->GetAppSetting(strDatabaseSection, strKeyDbUserId);
    iStrlen = strDatabaseUserId.length();
    if (iStrlen == 0)
    {
        bOK = AppSettings->SetAppSetting(strDatabaseSection,strKeyDbUserId,strDatabaseUserIdDef);
        strDatabaseUserId = strDatabaseUserIdDef;
    }
    strDatabasePassword = AppSettings->GetAppSetting(strDatabaseSection, strKeyDbPassword);
    iStrlen = strDatabasePassword.length();
    if (iStrlen == 0)
    {
        bOK = AppSettings->SetAppSetting(strDatabaseSection,strKeyDbPassword,strDatabasePasswordDef);
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
bool EnergyUsageDatabase::AddRecord(QStringList *stlInputValues)
{
    bool
        bTableFound = false;

    int
        iCnt1,
        iCnt2,
        iNbValues;  // Number of values in input stringlist

    QString
        strQuery,
        strStartDate,
        strStartTime,
        strEndDate,
        strEndTime,
        strTableName,
        strTemp;

    QStringList
        stlTableFields;

    //-----------------------------------------------------------------------------------
    //
    //  Get number of values
    //
    iNbValues = stlInputValues->size();

    //-----------------------------------------------------------------------------------
    //
    //  Prepare query for Elec table
    //
    if ((stlInputValues->at(0) == "elec")&&
        (iNbValues == iElecValueNb))
    {
        stlTableFields = stlElecTableFieldNames;
        strTableName = strTblElecName;
        bTableFound = true;
    }
    //-----------------------------------------------------------------------------------
    //
    //  Prepare query for Gas table
    //
    if ((stlInputValues->at(0) == "gas")&&
        (iNbValues == iGasValueNb))
    {
        stlTableFields = stlGasTableFieldNames;
        strTableName = strTblGasName;
        bTableFound = true;
    }
    //-----------------------------------------------------------------------------------
    //
    //  Prepare query for Water table
    //
    if ((stlInputValues->at(0) == "water")&&
        (iNbValues == iWaterValueNb))
    {
        stlTableFields = stlWaterTableFieldNames;
        strTableName = strTblWaterName;
        bTableFound = true;
    }

    //-----------------------------------------------------------------------------------
    //
    //  Check if table is found
    //
    if (!bTableFound)
        return false;

    //-------------------------------------------------------------------------------
    //
    //  Convert timestamps input file to postgress format
    //
    strTemp = stlInputValues->at(1);
    ConvertTimeStamp(&strTemp,strStartDate,strStartTime);
    strTemp = stlInputValues->at(2);
    ConvertTimeStamp(&strTemp,strEndDate,strEndTime);

    //-------------------------------------------------------------------------------
    //
    //  Build first part of insert query
    //
    strQuery = "INSERT INTO " + strTableName + " (";
    for (iCnt1 = 1; iCnt1 < stlTableFields.size(); iCnt1++)
    {
        strQuery.append(stlTableFields.at(iCnt1));
        if (iCnt1 != (stlTableFields.size() - 1))
            strQuery.append(", ");
        else
        {
            strQuery.append(") VALUES ('");
            strQuery.append(strStartDate);
            strQuery.append("', '");
            strQuery.append(strStartTime);
            strQuery.append("', '");
            strQuery.append(strEndDate);
            strQuery.append("', '");
            strQuery.append(strEndTime);
        }
    }

    //-------------------------------------------------------------------------------
    //
    //  Build second part of insert query
    //
    for (iCnt2 = 3; iCnt2 < iNbValues; iCnt2++)
    {
        // skip empty field in gas input file
        if ((iCnt2 == 6)&&(strTableName == strTblGasName))
            continue;
        // skip value "Totaal"
        if ((iCnt2 == 7)&&(strTableName == strTblElecName))
            continue;

        //  Append value
        strQuery.append("', '");
        strQuery.append(stlInputValues->at(iCnt2));
    }
    strQuery.append("');");

    //-----------------------------------------------------------------------------------
    //
    //  Write record to database
    //
    return ExecQuery(&strQuery);

}

//---------------------------------------------------------------------------------------
//
//  Open import file
//
bool EnergyUsageDatabase::ExtractValuesForLine(QString *strMetricType, QString *strInputLine)
{
    int
        iInputStringLength,         // length of the input string
        iInputStringUsed    = 0,    // position in inputstring
        iValueCnt           = 0,
        iValueLength;               // length of the value string

    QString
        strTemp;

    QStringList
        stlRecordValues;// list with record values includes metric type

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
int EnergyUsageDatabase::ImportMetricsFile(QString *strMetricFileType, QString *strImportFileName)
{
    int iTotalLines = 0,
        iTotalRecords = 0;

    QString
        strInputLine,
        strTemp;

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
        strSeverity = "Info";
        strLogMessage = "Import file: " + *strImportFileName + " succesfully opened";
        dbApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);

        //-------------------------------------------------------------------------------
        //
        //  Process file line by line
        //
        QTextStream qtsImportFile(&qfiImportFile);
        //  read header line and first line with metrics
        strInputLine = qtsImportFile.readLine();
        strInputLine = qtsImportFile.readLine();
        while (!qtsImportFile.atEnd())
        {
            strInputLine = ReFormatString(&strInputLine);
            iTotalRecords = ExtractValuesForLine(strMetricFileType,&strInputLine) + iTotalRecords;
            iTotalLines++;
            // read next line, when last line of import file it is skipped because this is
            // a total period row. Invalid for the database
            strInputLine = qtsImportFile.readLine();
        }
        qfiImportFile.close();

        //-------------------------------------------------------------------------------
        //
        //  Write to application log number of imported records
        strTemp = QString("%1").arg(iTotalRecords);
        strSeverity = "Info";
        strLogMessage = "Total number " + *strMetricFileType + " records added: " + strTemp;
        dbApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
    }
    else
    {
        //-------------------------------------------------------------------------------
        //
        //  Opening import file failed
        strSeverity = "Error";
        strLogMessage = "Failed to open import file: " + *strImportFileName;
        dbApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);

    }
    return(iTotalRecords);
}

//---------------------------------------------------------------------------------------
//
//  Convert timestmap format from yyyy-mm-dd hh:mm to (m)m/(d)d/yyyy (h)h:mm:00.000
//
void EnergyUsageDatabase::ConvertTimeStamp(QString *strTimeStampIn, QString &strDateOut,
                                  QString &strTimeOut)
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
    strTemp = QString("%1").arg(iYear);
    strTemp.append("/");
    strTemp.append(QString("%1").arg(iMonth));
    strTemp.append("/");
    strTemp.append(QString("%1").arg(iDay));
    strDateOut = strTemp;

    strTemp = QString("%1").arg(iHour);
    strTemp.append(":");
    strTemp.append(QString("%1").arg(iMinute,2,10,QChar('0')));
    strTemp.append(":00.000");
    strTimeOut = strTemp;

}

//---------------------------------------------------------------------------------------
//
//  Execute Query
//
bool EnergyUsageDatabase::ExecQuery(QString *strQuery)
{
    QSqlQuery qQuery("",sdbEnergyUsage);
    if (qQuery.exec(*strQuery))
        return true;
    else
    {
        strSeverity = "Error";
        strLogMessage = "Query: " + *strQuery + " failed";
        dbApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
        return false;
    }

}

//---------------------------------------------------------------------------------------
//
//  Reformats the input string
//  Removes . in the numeric values
//  Replaces , with . in the numeric values
//
QString EnergyUsageDatabase::ReFormatString(QString *strInputLine)
{
    QString
        strTemp;

    //---------------------------------------------------------------------------------------
    //
    //  Reformats the input string
    //  Removes . in the numeric values
    //  Replaces , with . in the numeric values
    strTemp = *strInputLine;
    strTemp.remove(".");
    strTemp.replace(",",".");

    return strTemp;

}
