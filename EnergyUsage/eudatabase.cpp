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
    euConnectDB(ApplicationLog,&strDatabaseName,&strDatabaseServerName,&strDatabaseUserId,&strDatabasePassword);


}

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
