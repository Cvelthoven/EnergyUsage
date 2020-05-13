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

#include "applicationsettings.h"
#include "applicationlogging.h"

class EnergyUsageDatabase : public QStandardItemModel
{
    Q_OBJECT

public:
    EnergyUsageDatabase(QObject *parent, ApplicationLogging *ApplicationLog);
    ~EnergyUsageDatabase();
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

    int iGasValueNb     = 9,    // number of expected fields in gas import file
        iElecValueNb    = 10,   // number of expected fields in electricity import file
        iWaterValueNb   = 6;    // number of expected fields in water import file

    QSqlDatabase
        sdbEnergyUsage;

//---------------------------------------------------------------------------------------
//
//  Application settings
//
ApplicationSettings *AppSettings;
ApplicationLogging *dbApplicationLog;

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
    //  Resource table names
QString
    strTblGasName   = "eu_gas_usage",
    strTblElecName  = "eu_elec_usage",
    strTblWaterName = "eu_water_usage";

QStringList
    //-----------------------------------------------------------------------------------
    //
    // Field names and types of eu_elec_usage
    //
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
    },
    //-----------------------------------------------------------------------------------
    //
    //  Field names and types of eu_elec_usage
    //  Total field in import file is excluded
    //
    stlElecTableFieldNames =
    {
        "eu_elec_rec_id",
        "eu_elec_date_start",
        "eu_elec_time_start",
        "eu_elec_date_end",
        "eu_elec_time_end",
        "eu_elec_usage_low_tarif",
        "eu_elec_usage_high_tarif",
        "eu_elec_return_low_tarif",
        "eu_elec_return_high_tarif",
        "eu_elec_expected_usage",
        "eu_elec_result"
    },
    stlElecTableFieldTypes =
    {
        "SERIAL PRIMARY KEY",
        "date",
        "time without time zone",
        "date",
        "time without time zone",
        "numeric(10,5)",
        "numeric(10,5)",
        "numeric(10,5)",
        "numeric(10,5)",
        "numeric(10,5)",
        "integer",
    },
    //-----------------------------------------------------------------------------------
    //
    // Field names and types of eu_water_usage
    //
    stlWaterTableFieldNames =
    {
        "eu_water_rec_id",
        "eu_water_date_start",
        "eu_water_time_start",
        "eu_water_date_end",
        "eu_water_time_end",
        "eu_water_actual_usage",
        "eu_water_expected_usage",
        "eu_water_result",
    },
    stlWaterTableFieldTypes =
    {
        "SERIAL PRIMARY KEY",
        "date",
        "time without time zone",
        "date",
        "time without time zone",
        "numeric(10,4)",
        "numeric(10,4)",
        "integer"
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
