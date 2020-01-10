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
    ConnectDB(&strAppLogDatabaseName, &strAppLogDatabaseServerName, &strAppLogDatabaseUserId, &strAppLogDatabasePassword);

}


//---------------------------------------------------------------------------------------
//
//  euConnectDB
//
//  Connects to the database and verifies that the tables exist or let them be created
//
bool euApplicationLogging::ConnectDB(QString *strDatabaseName, QString *strHostName, QString *strUserId, QString *strPassword)
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
    sdbAppLogDB = QSqlDatabase::addDatabase("QPSQL");
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
    strQuery = "CREATE TABLE " + strAppLogTblNameApplicationLog + " (";
    strQuery.append(strAppLogFldAplRecId + " SERIAL PRIMARY KEY, ");
    strQuery.append(strAppLogFldAplApplicationName + " text NOT NULL, ");
    strQuery.append(strAppLogFldAplTimeStamp + " timestamp without time zone NOT NULL, ");
    strQuery.append(strAppLogFldAplLogSeverity + " text NOT NULL, ");
    strQuery.append(strAppLogFldAplLogMessage + " text NOT NULL");
    strQuery.append(");");

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
//INSERT INTO application_log (apl_log_application_name, apl_log_time_stamp, apl_log_severity,apl_log_message) VALUES ('test','1/3/2019 12:38:00.123','info','Program started');
//
void euApplicationLogging::WriteLogRecord(const QString *strAppName, const QDateTime *qdRecTimeStamp, const QString *strLogSeverity, const QString *strLogMessage)
{
    QString strQuery,
            strRecTimeStamp,
            strTimeStampFormat = "yyyy-MM-dd hh:mm:ss.zzz",
            strTemp;
    strQuery = "INSERT INTO " + strAppLogTblNameApplicationLog + " (";
    // Fields
    strQuery.append(strAppLogFldAplApplicationName + ", ");
    strQuery.append(strAppLogFldAplTimeStamp + ", ");
    strQuery.append(strAppLogFldAplLogSeverity + ", ");
    strQuery.append(strAppLogFldAplLogMessage + ")");
    strQuery.append(" VALUES (\'");
    // Values
    strQuery.append(strAppName);
    strQuery.append("\', \'");
    strTemp = qdRecTimeStamp->toString(strTimeStampFormat);
    strQuery.append(strTemp);
    strQuery.append("\', \'");
    strQuery.append(strLogSeverity);
    strQuery.append("\', \'");
    strQuery.append(strLogMessage);
    strQuery.append("\');");

    // Write record to log database
    QSqlQuery qQuery("",sdbAppLogDB);
    if (!qQuery.exec(strQuery))
    {
        qDebug() << sdbAppLogDB.lastError();
    }

}
