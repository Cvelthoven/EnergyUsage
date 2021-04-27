//---------------------------------------------------------------------------------------
//
//  euapplicationlogging
//
//  This class handles all application logging to a database or file
//
#include "applicationlogging.h"
#include "applicationsettingsmodel.h"
#include "energyusage.h"

#include <QCoreApplication>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QtSql>

#include <QDebug>

//---------------------------------------------------------------------------------------
//
//  Default constructor
//
ApplicationLogging::ApplicationLogging(QObject *parent)
        : QStandardItemModel(parent)
{
    //-----------------------------------------------------------------------------------
    //
    //  Retrieve application logging configuration
    AplLogingSettings = new ApplicationSettingsModel();
    RetrieveLogConfig();
    if (ConnectDB(&strAppLogDatabaseName, &strAppLogDatabaseServerName,
                  &strAppLogDatabaseUserId, &strAppLogDatabasePassword))
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
//  Destructor including disconnect from logging database
//
ApplicationLogging::~ApplicationLogging()
{
    sdbAppLogDB.close();

}


//---------------------------------------------------------------------------------------
//
//  euConnectDB
//
//  Connects to the database and verifies that the tables exist or let them be created
//
bool ApplicationLogging::ConnectDB(QString *strDatabaseName, QString *strHostName,
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
        SendWarningMessage("PostgreSql driver", "not found");
        return false;
    }

    //-----------------------------------------------------------------------------------
    //
    //  Open database
    //
    sdbAppLogDB = QSqlDatabase::addDatabase("QPSQL","ApplicationLog");
    sdbAppLogDB.setHostName(*strHostName);
    sdbAppLogDB.setDatabaseName(*strDatabaseName);
    sdbAppLogDB.setPort(-1);
    if (!sdbAppLogDB.open(*strUserId,*strPassword))
    {
        SendWarningMessage(*strDatabaseName, "not found");
        return false;
    }

    //-----------------------------------------------------------------------------------
    //
    //  Check tables
    //
    stlAplLogTables = sdbAppLogDB.tables();
    //
    //  Check application_log table exists
    if (!stlAplLogTables.contains(strAppLogTblNameApplicationLog))
    {
        if (!LogCreateTable())
        {
            SendWarningMessage(strAppLogTblNameApplicationLog, "could not be created");
            return false;
        }
    }

    return true;
}


//---------------------------------------------------------------------------------------
//
//  euLogCreateTable
//
//  Creates the table: application_log
//
bool ApplicationLogging::LogCreateTable()
{
QString
    strQuery;

    //-----------------------------------------------------------------------------------
    //
    //  Build build query of strTblGasName
    strQuery = "CREATE TABLE " + strAppLogTblNameApplicationLog + " (" +
                strAppLogFldAplRecId + " SERIAL PRIMARY KEY, " +
                strAppLogFldAplApplicationName + " text NOT NULL, " +
                strAppLogFldAplTimeStamp + " timestamp without time zone NOT NULL, " +
                strAppLogFldAplLogSeverity + " text NOT NULL, " +
                strAppLogFldAplLogMessage + " text NOT NULL);";

    //-----------------------------------------------------------------------------------
    //
    //  Create eu_gas_usage table
    //
    QSqlQuery qQuery("",sdbAppLogDB);
    if (!qQuery.exec(strQuery))
    {
        qDebug() << sdbAppLogDB.lastError();
        return false;
    }

    return true;
}


//---------------------------------------------------------------------------------------
//
//  Retrieve application logging configuration
//
bool ApplicationLogging::RetrieveLogConfig()
{
    bool
        bOK = true;

    int iStrlen;

    //-----------------------------------------------------------------------------------
    //
    //  Check type of logging
    //
    strAppLogLoggingType = AplLogingSettings->GetAppSetting(strAppLogSectionName, strAppLogKeyLoggingType);
    iStrlen = strAppLogLoggingType.length();
    if (iStrlen == 0)
    {
        SendWarningMessage(strAppLogKeyLoggingType,"Logging type not set.");
    }

    //-----------------------------------------------------------------------------------
    //
    //  Get datbase configuration
    //
    if (strAppLogLoggingType == "db")
    {
        //  Get database servername
        strAppLogDatabaseServerName = AplLogingSettings->GetAppSetting(strAppLogSectionName, strAppLogKeyDbServerName);
        iStrlen = strAppLogDatabaseServerName.length();
        if (iStrlen == 0)
        {
            SendWarningMessage(strAppLogKeyLoggingType,"Database server not set.");
        }
        //
        //  Get database name
        strAppLogDatabaseName = AplLogingSettings->GetAppSetting(strAppLogSectionName, strAppLogKeyDbName);
        iStrlen = strAppLogDatabaseName.length();
        if (iStrlen == 0)
        {
            SendWarningMessage(strAppLogKeyLoggingType,"Database name not set");
        }
         //
        //  Get database Username
        strAppLogDatabaseUserId = AplLogingSettings->GetAppSetting(strAppLogSectionName, strAppLogKeyDbUserId);
        iStrlen = strAppLogDatabaseUserId.length();
        if (iStrlen == 0)
        {
            SendWarningMessage(strAppLogKeyLoggingType,"Logging database userid not set.");
        }
        //
        //  Get database Password
        strAppLogDatabasePassword = AplLogingSettings->GetAppSetting(strAppLogSectionName, strAppLogKeyDbPassword);
        iStrlen = strAppLogDatabasePassword.length();
        if (iStrlen == 0)
        {
            SendWarningMessage(strAppLogKeyLoggingType,"Logging database password not set.");
        }
        return(bOK);
    }
    else
    {
        //-------------------------------------------------------------------------------
        //
        //  Get log file configuration
        //
        if (strAppLogLoggingType == "file")
        {
            return false;
        }
        else
        //-------------------------------------------------------------------------------
        //
        //  Unknown log type defined
        //
        {
            return false;
        }
    }
}


//---------------------------------------------------------------------------------------
//
//  Display warning message log configuration
//
void ApplicationLogging::SendWarningMessage(const QString &strMsgPart1, const QString &strMsgPart2)
{
    QMessageBox msgBox;
    QString euMessage;

    euMessage = strMsgPart1 + ": " + strMsgPart2;
    msgBox.setText(euMessage);
    msgBox.exec();
    qDebug() << strMsgPart1 << ", " << strMsgPart2;

}

//---------------------------------------------------------------------------------------
//
//  Write a log record with predefined application name and without timestamp set
//
void ApplicationLogging::WriteLogRecord(const QString *strLogSeverity, const QString *strLogMessage)
{
    //-----------------------------------------------------------------------------------
    //
    //  Get current timestamp

#include "QObject.h"

// Constructors/Destructors
//  

QObject::QObject()
{
}

QObject::~QObject()
{
}

//  
// Methods
//  


// Accessor methods
//  


// Other methods
//  


