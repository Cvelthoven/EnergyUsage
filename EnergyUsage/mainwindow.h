#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

#include "euapplicationsettings.h"
#include "euapplicationlogging.h"
#include "eudatabase.h"
#include "importmetricsfile.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    euApplicationSettings   *ApplicationSettings;
    euApplicationLogging    *ApplicationLog;

    bool InitializeProgram();

private slots:
    void on_actionExit_triggered() __attribute__ ((noreturn));

    void on_actionGas_triggered();

private:
    Ui::MainWindow *ui;

    euDatabase *Database;

    ImportMetricsFile *GasImportFile;

    QString
        strGasImportFileName,
        strTemp,
        strSeverity,
        strMessage;

};

#endif // MAINWINDOW_H
