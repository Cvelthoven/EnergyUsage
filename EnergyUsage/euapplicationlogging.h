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
#include <QString>

#include "euapplicationsettings.h"

class euApplicationLogging
{
public:
    euApplicationLogging(QObject *parent);
    void euRetrieveLogConfig();

private:
    euApplicationSettings *euAplLogingSettings;

    QString
        strAppLogSectionName = "Loging",                    // Application logging section name
        strAppLogKeyLoggingType = "LoggingType",            // Key name with the type of log (db or file)
        strAppLogLoggingTypeDef = "db",                     // Default application logging type
        strAppLogKeyDbServerName = "LogDatabaseServerName", // Key name with application logging database server name
        strAppLogDatabaseServerNameDef = "192.168.1.51",    // Default application logging database server
        strAppLogDatabaseServerName,                        // Application Logging database server name
        //-------------------------------------------------------------------------------
        strAppLogKeyDbName = "DatabaseName",                // Key name with database name
        strAppLogDatabaseNameDef = "cvraspi01dev",          // Default database name
        strAppLogDatabaseName,                              // Database name
        //-------------------------------------------------------------------------------
        strAppLogKeyDbUserId = "DatabaseUserId",            // Key name with database UserID
        strAppLogDatabaseUserIdDef = "pi",                  // Default database UserID
        strAppLogDatabaseUserId,                            // Database userID
        //-------------------------------------------------------------------------------
        strAppLogKeyDbPassword = "DatabasePassword",        // Key name with database Password
        strAppLogDatabasePasswordDef = "#NS01fr#LDrz76#",   // Default database Password
        strAppLogDatabasePassword;                          // Database password

    //-----------------------------------------------------------------------------------
    //
    //  Application logfile database table and field names
    //
    QString
        strAppLogTblNameApplicationLog    = "application_log",
        strAppLogFldAplRecId              = "apl_rec_id",
        strAppLogFldAplApplicationName    = "apl_application_name",
        strAppLogFldAplTimeStamp          = "apl_time_stamp",
        strAppLogFldAplLogMessage         = "apl_log_message";

};

#endif // EUAPPLICATIONLOGGING_H
