#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>

#include "applicationsettingsmodel.h"
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

    ApplicationSettingsModel   *AppSettings;
    ApplicationLogging    *AppLogging;

    bool InitializeProgram();

private slots:
    void on_actionExit_triggered();

    void on_actionGas_triggered();

    void on_actionElectricity_triggered();

    void on_actionWater_triggered();

    void on_applicationServerLineEdit_returnPressed();

    void on_applicationDatabaseLineEdit_returnPressed();

    void on_applicationDatabaseUseridLineEdit_returnPressed();

    void on_applicationDatabasePasswordLineEdit_returnPressed();

    void on_btnExit_clicked();

    void on_btnStart_clicked();

    void on_loggingServerLineEdit_returnPressed();

    void on_loggingDatabaseLineEdit_returnPressed();

    void on_loggingUseridLineEdit_returnPressed();

    void on_loggingPasswordLineEdit_returnPressed();

    void on_stackedWidget_currentChanged(int arg1);

private:
    void chartGasLineSetup();
    void goExit() __attribute__ ((noreturn));
    bool retrieveDbLogSettings();
    void resizeEvent(QResizeEvent* event);
    void setupMenuBar();

    bool
        bAppLogConnected   = false,
        bDatabaseConnected = false;

    Ui::MainWindow *ui;

    EnergyUsageDatabase *Database;

    QChartView *chartGasLine;

    QString
        strImportFileName,
        strTemp,
        strSeverity,
        strMessage;

    QString
        strAppDbSectionName = "AplDatabase",             // Application database section name
        //-------------------------------------------------------------------------------
        strAppKeyDbServerName = "AplDatabaseServerName", // Key name with application database server name
        strAppDatabaseServerName,                        // Application database server name
        //-------------------------------------------------------------------------------
        strAppKeyDbName = "AplDatabaseName",             // Key name with database name
        strAppDatabaseName,                              // Database name
        //-------------------------------------------------------------------------------
        strAppKeyDbUserId = "AplDatabaseUserId",         // Key name with database UserID
        strAppDatabaseUserId,                            // Database userID
         //-------------------------------------------------------------------------------
        strAppKeyDbPassword = "AplDatabasePassword",     // Key name with database Password
        strAppDatabasePassword;                          // Database password

    QString
        strAppLogSectionName = "Log",                       // Application logging section name
        strAppLogKeyLoggingType = "LogType",                // Key name with the type of log (db or file)
        strAppLogLoggingType,                               // Application loggging type
        //-------------------------------------------------------------------------------
        strAppLogKeyDbServerName = "LogDatabaseServerName", // Key name with application logging database server name
        strAppLogDatabaseServerName,                        // Application Logging database server name
        //-------------------------------------------------------------------------------
        strAppLogKeyDbName = "LogDatabaseName",             // Key name with database name
        strAppLogDatabaseName,                              // Database name
        //-------------------------------------------------------------------------------
        strAppLogKeyDbUserId = "LogDatabaseUserId",         // Key name with database UserID
        strAppLogDatabaseUserId,                            // Database userID
         //-------------------------------------------------------------------------------
        strAppLogKeyDbPassword = "LogDatabasePassword",        // Key name with database Password
        strAppLogDatabasePassword;                          // Database password

};

#endif // MAINWINDOW_H
