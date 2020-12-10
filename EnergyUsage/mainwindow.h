#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

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
    void on_actionExit_triggered() __attribute__ ((noreturn));

    void on_actionGas_triggered();

    void on_actionElectricity_triggered();

    void on_actionWater_triggered();

private:
    void setupMenuBar();

    Ui::MainWindow *ui;

    EnergyUsageDatabase *Database;

    QString
        strImportFileName,
        strTemp,
        strSeverity,
        strMessage;

};

#endif // MAINWINDOW_H
