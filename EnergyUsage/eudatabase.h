#ifndef EUDATABASE_H
#define EUDATABASE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include <QMessageBox>
#include <QSqlDatabase>
#include <QStandardItemModel>
#include <QString>
#include <QStringList>

#include "euapplicationsettings.h"

class euDatabase : public QStandardItemModel
{
    Q_OBJECT

public:
    euDatabase(QObject *parent);
    bool euConnectDB(QString *strDatabaseName, QString *strHostName, QString *strUserId, QString *strPassword);
    bool euRetrieveConfig();

private:
    QSqlDatabase
        sdbEnergyUsage;

//---------------------------------------------------------------------------------------
//
//  Application settings
//
euApplicationSettings *ApplicationSettings;

QString
    strDatabaseSection = "Database",            // Database section name
    strKeyDbServerName = "DatabaseServerName",  // Key name with database server name
    strDatabaseServerNameDef = "192.168.1.51",  // Default database server
    strDatabaseServerName,                      // Database server name
    //-------------------------------------------------------------------------------
    strKeyDbName = "DatabaseName",              // Key name with database name
    strDatabaseNameDef = "cvraspi01dev",        // Default database name
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
    //
    //  euGas table names
QString
    strTblGasName       = "euGasUsage",
    strFldGasRecId      = "euGasRecId",
    strFldDateStart     = "euGasDateStart",
    strFldTimeStart     = "euGasTimeStart",
    strFldDateEnd       = "euGasDateEnd",
    strFldTimeEnd       = "euGasTimeEnd",
    strFldActualUsage   = "euGasActualUsage",
    strFldExpectedUsage = "euGasExpectedUsage",
    strFldResult        = "euGasResult",
    strFldDegreeDay     = "euGasDegreeDay",
    strFldPerDegreeDay  = "euGasPerDegreeDay";

QStringList
    stlDbTables;

};

#endif // EUDATABASE_H
