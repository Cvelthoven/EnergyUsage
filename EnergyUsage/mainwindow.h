#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QString>

#include "applicationsettingsmodel.h"
#include "applicationsettingsview.h"
#include "applicationlogging.h"
#include "energyusagedatabase.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    ApplicationSettingsView *ApplicationSettings;

    ApplicationLogging *AppLogging;

    bool InitializeProgram();

    QLabel
        *statusApplication,
        *statusAplDb,
        *statusLogging;

private slots:
    // File menu actions
    void on_actionExit_triggered();

    void on_actionGas_triggered();

    void on_actionElectricity_triggered();

    void on_actionWater_triggered();

    // Options menu actions
    void on_actionConfiguration_triggered();

private:
    void goExit() __attribute__ ((noreturn));
    bool retrieveDbLogSettings();

    bool
        bAppLogConnected   = false,
        bDatabaseConnected = false;

    Ui::MainWindow *ui;

    EnergyUsageDatabase *Database;

    QString
        strImportFileName,
        strTemp,
        strSeverity,
        strMessage;

    QString
        strAppDbSectionName = "AplDatabase",             // Application database section name
        //-------------------------------------------------------------------------------
 //       strAppKeyDbServerName = "AplDatabaseServerName", // Key name with application database server name
        strAppDatabaseServerName,                        // Application database server name
        //-------------------------------------------------------------------------------
//        strAppKeyDbName = "AplDatabaseName",             // Key name with database name
        strAppDatabaseName,                              // Database name
        //-------------------------------------------------------------------------------
//        strAppKeyDbUserId = "AplDatabaseUserId",         // Key name with database UserID
        strAppDatabaseUserId,                            // Database userID
         //-------------------------------------------------------------------------------
//        strAppKeyDbPassword = "AplDatabasePassword",     // Key name with database Password
        strAppDatabasePassword;                          // Database password

    QString
//        strAppLogSectionName = "Log",                       // Application logging section name
//        strAppLogKeyLoggingType = "LogType",                // Key name with the type of log (db or file)
        strAppLogLoggingType,                               // Application loggging type
        //-------------------------------------------------------------------------------
//        strAppLogKeyDbServerName = "LogDatabaseServerName", // Key name with application logging database server name
        strAppLogDatabaseServerName,                        // Application Logging database server name
        //-------------------------------------------------------------------------------
//        strAppLogKeyDbName = "LogDatabaseName",             // Key name with database name
        strAppLogDatabaseName,                              // Database name
        //-------------------------------------------------------------------------------
//        strAppLogKeyDbUserId = "LogDatabaseUserId",         // Key name with database UserID
        strAppLogDatabaseUserId,                            // Database userID
         //-------------------------------------------------------------------------------
//        strAppLogKeyDbPassword = "LogDatabasePassword",        // Key name with database Password
        strAppLogDatabasePassword;                          // Database password

};

#endif // MAINWINDOW_H
