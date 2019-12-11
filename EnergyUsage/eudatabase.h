#ifndef EUDATABASE_H
#define EUDATABASE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include <QMessageBox>
#include <QSqlDatabase>
#include <QString>
#include <QStringList>

#include "euapplicationsettings.h"

class euDatabase
{

public:
    euDatabase();
    bool euConnectDB(QString *strDatabaseName, QString *strHostName, QString *strUserId, QString *strPassword);
    bool euRetrieveConfig();

private:
//---------------------------------------------------------------------------------------
//
//  Application settings
//
QString
    strDatabaseSection = "Database",            // Database section name
    strKeyDbServerName = "DatabaseServerName",  // Key name with database server name
    strDatabaseServerNameDef = "cvraspi01",     // Default database server
    strDatabaseServerName,                      // Database server name
    //-------------------------------------------------------------------------------
    strKeyDbName = "DatabaseName",              // Key name with database name
    strDatabaseNameDef = "cvraspi01Dev",        // Default database name
    strDatabaseName,                            // Database name
    //-------------------------------------------------------------------------------
    strKeyDbUserId = "DatabaseUserId",          // Key name with database UserID
    strDatabaseUserIdDef = "pi",                // Default database UserID
    strDatabaseUserId,                          // Database userID
    //-------------------------------------------------------------------------------
    strKeyDbPassword = "DatabasePassword",      // Key name with database Password
    strDatabasePasswordDef = "#NS01fr#LDrz76#", // Default database Password
    strDatabasePassword;                        // Database password
    //-------------------------------------------------------------------------------

    euApplicationSettings *ApplicationSettings;

//    QSqlDatabase
//        sdbEnergyUsage;

//    QMessageBox
//        msgBox;

};

#endif // EUDATABASE_H
