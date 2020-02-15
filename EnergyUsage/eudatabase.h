//---------------------------------------------------------------------------------------
//
//  Class euDatabase
//
//  This class handles the data interaction with the underlying database
//
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
#include "euapplicationlogging.h"

class euDatabase : public QStandardItemModel
{
    Q_OBJECT

public:
    euDatabase(QObject *parent, euApplicationLogging *ApplicationLog);
    bool euConnectDB(euApplicationLogging *ApplicationLog, QString *strDatabaseName, QString *strHostName, QString *strUserId, QString *strPassword);
    bool euGasCreateTable();
    bool euRetrieveConfig();
    int ImportMetricsFile(QString *strMetricFileType, QString *strImportFileName);

    bool
        bDBconnected;

private:
    bool AddRecord(QStringList *stlInputValues);
    bool ExtractValuesForLine(QString *strMetricFileType, QString *strInputLine);

    QSqlDatabase
        sdbEnergyUsage;

//---------------------------------------------------------------------------------------
//
//  Application settings
//
euApplicationSettings *ApplicationSettings;

QString
    strDatabaseSection = "AplDatabase",             // Database section name
    strKeyDbServerName = "AplDatabaseServerName",   // Key name with database server name
    strDatabaseServerNameDef = "192.168.1.51",      // Default database server
    strDatabaseServerName,                          // Database server name
    //-------------------------------------------------------------------------------
    strKeyDbName = "AplDatabaseName",               // Key name with database name
    strDatabaseNameDef = "cvraspi01dev",            // Default database name
    strDatabaseName,                                // Database name
    //-------------------------------------------------------------------------------
    strKeyDbUserId = "AplDatabaseUserId",           // Key name with database UserID
    strDatabaseUserIdDef = "pi",                    // Default database UserID
    strDatabaseUserId,                              // Database userID
    //-------------------------------------------------------------------------------
    strKeyDbPassword = "AplDatabasePassword",       // Key name with database Password
    strDatabasePasswordDef = "#NS01fr#LDrz76#",     // Default database Password
    strDatabasePassword;                            // Database password

    //-------------------------------------------------------------------------------
    //
    //  euGas table names
QString
    strTblGasName       = "eu_gas_usage",
    strFldGasRecId      = "eu_gas_rec_id",
    strFldDateStart     = "eu_gas_date_start",
    strFldTimeStart     = "eu_gas_time_start",
    strFldDateEnd       = "eu_gas_date_end",
    strFldTimeEnd       = "eu_gas_time_end",
    strFldActualUsage   = "eu_gas_actual_usage",
    strFldExpectedUsage = "eu_gas_expected_usage",
    strFldResult        = "eu_gas_result",
    strFldDegreeDay     = "eu_gas_degree_day",
    strFldPerDegreeDay  = "eu_gas_per_degree_day";

//-----------------------------------------------------------------------------------
//
//  Application logfile database table and field names
//
QString
    strTblNameApplicationLog    = "application_log",
    strFldAplRecId              = "apl_rec_id",
    strFldAplApplicationName    = "apl_application_name",
    strFldAplTimeStamp          = "apl_time_stamp",
    strFldAplLogMessage         = "apl_log_message";

QString
    strMetricType;  // metric type indicator (gas, elek, water)

QStringList
    stlDbTables,    // list with tables in database
    stlRecordValues;// list with record values includes metric type

};

#endif // EUDATABASE_H
