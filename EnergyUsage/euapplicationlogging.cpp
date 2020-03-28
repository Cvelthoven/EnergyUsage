//---------------------------------------------------------------------------------------
//
//  euapplicationlogging
//
//  This class handles all application logging to a database or file
//
#include "euapplicationlogging.h"
#include "euapplicationsettings.h"
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
euApplicationLogging::euApplicationLogging(QObject *parent)
        : QStandardItemModel(parent)
{
    //-----------------------------------------------------------------------------------
    //
    //  Retrieve application logging configuration
    euAplLogingSettings = new euApplicationSettings();
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
euApplicationLogging::~euApplicationLogging()
{
    sdbAppLogDB.close();

}


//---------------------------------------------------------------------------------------
//
//  euConnectDB
//
//  Connects to the database and verifies that the tables exist or let them be created
//
bool euApplicationLogging::ConnectDB(QString *strDatabaseName, QString *strHostName,
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
bool euApplicationLogging::LogCreateTable()
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
bool euApplicationLogging::RetrieveLogConfig()
{
    bool
        bOK = true;

    int iStrlen;

    //-----------------------------------------------------------------------------------
    //
    //  Check type of logging
    //
    strAppLogLoggingType = euAplLogingSettings->euGetAppSetting(strAppLogSectionName, strAppLogKeyLoggingType);
    iStrlen = strAppLogLoggingType.length();
    if (iStrlen == 0)
    {
        bOK = euAplLogingSettings->euSetAppSetting(strAppLogSectionName,strAppLogKeyLoggingType,strAppLogLoggingTypeDef);
        if(!bOK)
            SendWarningMessage(strAppLogKeyLoggingType,"Unable to write to configuration.");
        strAppLogLoggingType = strAppLogLoggingTypeDef;
    }

    //-----------------------------------------------------------------------------------
    //
    //  Get datbase configuration
    //
    if (strAppLogLoggingType == "db")
    {
        //  Get database servername
        strAppLogDatabaseServerName = euAplLogingSettings->euGetAppSetting(strAppLogSectionName, strAppLogKeyDbServerName);
        iStrlen = strAppLogDatabaseServerName.length();
        if (iStrlen == 0)
        {
            bOK = euAplLogingSettings->euSetAppSetting(strAppLogSectionName,strAppLogKeyDbServerName,strAppLogDatabaseServerNameDef);
            if(!bOK)
                SendWarningMessage(strAppLogKeyLoggingType,"Unable to write to configuration.");
            strAppLogDatabaseServerName = strAppLogDatabaseServerNameDef;
        }
        //
        //  Get database name
        strAppLogDatabaseName = euAplLogingSettings->euGetAppSetting(strAppLogSectionName, strAppLogKeyDbName);
        iStrlen = strAppLogDatabaseName.length();
        if (iStrlen == 0)
        {
            bOK = euAplLogingSettings->euSetAppSetting(strAppLogSectionName,strAppLogKeyDbName,strAppLogDatabaseNameDef);
            if(!bOK)
                SendWarningMessage(strAppLogKeyDbName,"Unable to write to configuration.");
            strAppLogDatabaseName = strAppLogDatabaseNameDef;
        }
        //
        //  Get database Username
        strAppLogDatabaseUserId = euAplLogingSettings->euGetAppSetting(strAppLogSectionName, strAppLogKeyDbUserId);
        iStrlen = strAppLogDatabaseUserId.length();
        if (iStrlen == 0)
        {
            bOK = euAplLogingSettings->euSetAppSetting(strAppLogSectionName,strAppLogKeyDbUserId,strAppLogDatabaseUserIdDef);
            if(!bOK)
                SendWarningMessage(strAppLogKeyDbUserId,"Unable to write to configuration.");
            strAppLogDatabaseUserId = strAppLogDatabaseUserIdDef;
        }
        //
        //  Get database Password
        strAppLogDatabasePassword = euAplLogingSettings->euGetAppSetting(strAppLogSectionName, strAppLogKeyDbPassword);
        iStrlen = strAppLogDatabasePassword.length();
        if (iStrlen == 0)
        {
            bOK = euAplLogingSettings->euSetAppSetting(strAppLogSectionName,strAppLogKeyDbPassword,strAppLogDatabasePasswordDef);
            if(!bOK)
                SendWarningMessage(strAppLogKeyDbPassword,"Unable to write to configuration.");
            strAppLogDatabasePassword = strAppLogDatabasePasswordDef;
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
void euApplicationLogging::SendWarningMessage(const QString &strMsgPart1, const QString &strMsgPart2)
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
void euApplicationLogging::WriteLogRecord(const QString *strLogSeverity, const QString *strLogMessage)
{
    //-----------------------------------------------------------------------------------
    //
    //  Get current timestamp
    //
    QDateTime LogTime = QDateTime::currentDateTime();

    //-----------------------------------------------------------------------------------
    //
    //  Retrieve application name and write log record
    //
     WriteLogRecord(&strApplicationName,&LogTime,strLogSeverity,strLogMessage);

}

//---------------------------------------------------------------------------------------
//
//  Write a log record with predefined application name
//
void euApplicationLogging::WriteLogRecord(const QDateTime *qdRecTimeStamp, const QString *strLogSeverity, const QString *strLogMessage)
{

    //-----------------------------------------------------------------------------------
    //
    //  Retrieve application name and write log record
    //
     WriteLogRecord(&strApplicationName,qdRecTimeStamp,strLogSeverity,strLogMessage);

}

//---------------------------------------------------------------------------------------
//  Write a log record
//
void euApplicationLogging::WriteLogRecord(const QString *strAppName,
                                          const QDateTime *qdRecTimeStamp,
                                          const QString *strLogSeverity,
                                          const QString *strLogMessage)
{
    QString strQuery,
            strRecTimeStamp,
            strTimeStampFormat = "yyyy-MM-dd hh:mm:ss.zzz",
            strTemp;

    //-----------------------------------------------------------------------------------
    //
    //  Build query
    strTemp = qdRecTimeStamp->toString(strTimeStampFormat);
    strQuery = "INSERT INTO " + strAppLogTblNameApplicationLog + " (" +
    // Fields
                strAppLogFldAplApplicationName + ", " +
                strAppLogFldAplTimeStamp + ", " +
                strAppLogFldAplLogSeverity + ", " +
                strAppLogFldAplLogMessage + ") VALUES (\'" +
    // Values
                strAppName + "\', \'" +
                strTemp + "\', \'" +
                strLogSeverity + "\', \'";

    //-----------------------------------------------------------------------------------
    //
    //  Reformat possible ' in message to ''
    //
    strTemp = *strLogMessage;
    strTemp.replace(QString("'"),QString("''"));
    strQuery.append(strTemp);
    strQuery.append("\');");

    // Write record to log database
    QSqlQuery qQuery("",sdbAppLogDB);
    if (!qQuery.exec(strQuery))
    {
        qDebug() << sdbAppLogDB.lastError();
    }

}
