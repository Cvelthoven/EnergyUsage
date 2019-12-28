//---------------------------------------------------------------------------------------
//
//  euapplicationlogging
//
//  This class handles all application logging to a database or file
//
#ifndef EUAPPLICATIONLOGGING_H
#define EUAPPLICATIONLOGGING_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include <QSqlDatabase>
#include <QStandardItemModel>
#include <QString>

#include "euapplicationsettings.h"

class euApplicationLogging : public QStandardItemModel
{
    Q_OBJECT

public:
    euApplicationLogging(QObject *parent);
    bool ConnectDB(QString *strDatabaseName, QString *strHostName, QString *strUserId, QString *strPassword);
    bool LogCreateTable();
    bool RetrieveLogConfig();
    void SendWarningMessage(const QString &strMsgPart1, const QString &strMsgPart2);

private:
    euApplicationSettings *euAplLogingSettings;

    QSqlDatabase sdbAppLogDB;

    QString
        strAppLogSectionName = "Log",                       // Application logging section name
        strAppLogKeyLoggingType = "LogType",                // Key name with the type of log (db or file)
        strAppLogLoggingTypeDef = "db",                     // Default application logging type
        strAppLogLoggingType,                               // Application loggging type
        //-------------------------------------------------------------------------------
        strAppLogKeyDbServerName = "LogDatabaseServerName", // Key name with application logging database server name
        strAppLogDatabaseServerNameDef = "192.168.1.51",    // Default application logging database server
        strAppLogDatabaseServerName,                        // Application Logging database server name
        //-------------------------------------------------------------------------------
        strAppLogKeyDbName = "LogDatabaseName",             // Key name with database name
        strAppLogDatabaseNameDef = "cvraspi01dev",          // Default database name
        strAppLogDatabaseName,                              // Database name
        //-------------------------------------------------------------------------------
        strAppLogKeyDbUserId = "LogDatabaseUserId",         // Key name with database UserID
        strAppLogDatabaseUserIdDef = "pi",                  // Default database UserID
        strAppLogDatabaseUserId,                            // Database userID
        //-------------------------------------------------------------------------------
        strAppLogKeyDbPassword = "LogDatabasePassword",        // Key name with database Password
        strAppLogDatabasePasswordDef = "#NS01fr#LDrz76#",   // Default database Password
        strAppLogDatabasePassword;                          // Database password

    //-----------------------------------------------------------------------------------
    //
    //  Application logfile database table and field names
    //
    QString
        strAppLogTblNameApplicationLog    = "application_log",
        strAppLogFldAplRecId              = "apl_log_rec_id",
        strAppLogFldAplApplicationName    = "apl_log_application_name",
        strAppLogFldAplTimeStamp          = "apl_log_time_stamp",
        strAppLogFldAplLogSeverity        = "apl_log_severity",
        strAppLogFldAplLogMessage         = "apl_log_message";

    QStringList stlAplLogTables;

};

#endif // EUAPPLICATIONLOGGING_H
