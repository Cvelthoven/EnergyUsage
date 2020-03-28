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
    ~euDatabase();
    bool euConnectDB(QString *strDatabaseName, QString *strHostName, QString *strUserId, QString *strPassword);
    bool CreateTable(const QString *strTableName, const QStringList *stlTableFieldNames, const QStringList *stlTableFieldTypes);
    bool euRetrieveConfig();
    int ImportMetricsFile(QString *strMetricFileType, QString *strImportFileName);

    bool
        bDBconnected;

private:
    bool AddRecord(QStringList *stlInputValues);
    void ConvertTimeStamp(QString *strTimeStampIn, QString &strDateOut, QString &strTimeOut);
    bool ExecQuery(QString *strQuery);
    bool ExtractValuesForLine(QString *strMetricFileType, QString *strInputLine);
    QString ReFormatString(QString *strInputLine);
    int iGasValueNb = 9;// number of expected fields in gas import file

    QSqlDatabase
        sdbEnergyUsage;

//---------------------------------------------------------------------------------------
//
//  Application settings
//
euApplicationSettings *ApplicationSettings;
euApplicationLogging *dbApplicationLog;

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
    strTblGasName           = "eu_gas_usage",
    strFldGasRecId          = "eu_gas_rec_id",
    strFldGasDateStart      = "eu_gas_date_start",
    strFldGasTimeStart      = "eu_gas_time_start",
    strFldGasDateEnd        = "eu_gas_date_end",
    strFldGasTimeEnd        = "eu_gas_time_end",
    strFldGasActualUsage    = "eu_gas_actual_usage",
    strFldGasExpectedUsage  = "eu_gas_expected_usage",
    strFldGasResult         = "eu_gas_result",
    strFldGasDegreeDay      = "eu_gas_degree_day",
    strFldGasPerDegreeDay   = "eu_gas_per_degree_day";

QStringList
    stlGasTableFieldNames =
    {
        "eu_gas_rec_id",
        "eu_gas_date_start",
        "eu_gas_time_start",
        "eu_gas_date_end",
        "eu_gas_time_end",
        "eu_gas_actual_usage",
        "eu_gas_expected_usage",
        "eu_gas_result",
        "eu_gas_degree_day",
        "eu_gas_per_degree_day"
    },
    stlGasTableFieldTypes =
    {
        "SERIAL PRIMARY KEY",
        "date",
        "time without time zone",
        "date",
        "time without time zone",
        "numeric(10,4)",
        "numeric(10,4)",
        "integer",
        "numeric(8,4)",
        "numeric(8,4)"
    };

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
    strMetricType,  // metric type indicator (gas, elek, water)
    strSeverity,    // severity value in log message
    strLogMessage;  // application log message

QStringList
    stlDbTables;    // list with tables in database

};

#endif // EUDATABASE_H
