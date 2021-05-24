#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QString>

#include "applicationsettingsmodel.h"
#include "applicationsettingsview.h"
#include "applicationlogging.h"
#include "energyusagedatabase.h"
#include "energyusagedatamodel.h"

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
    bool inititializeAppDatabase();
    bool inititializeLogging();
    bool retrieveDbLogSettings();

    bool
        bAppLogConnected   = false,
        bDatabaseConnected = false;

    Ui::MainWindow *ui;

    EnergyUsageDatabase *Database;// old class must be removed
    EnergyUsageDataModel *ApllicationDatabase;

    QString
        strImportFileName,
        strTemp,
        strSeverity,
        strMessage;

    QString
        strAppDatabaseServerName,// Application database server name
        strAppDatabaseName,      // Database name
        strAppDatabaseUserId,    // Database userID
        strAppDatabasePassword;  // Database password

    QString
        strAppLogLoggingType,       // Application loggging type
        strAppLogDatabaseServerName,// Application Logging database server name
        strAppLogDatabaseName,      // Database name
        strAppLogDatabaseUserId,    // Database userID
        strAppLogDatabasePassword;  // Database password

};

#endif // MAINWINDOW_H
