#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "euapplicationsettings.h"

#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    euApplicationSettings *ApplicationSettings;

    void InitializeProgram();

private:
    Ui::MainWindow *ui;

//---------------------------------------------------------------------------------------
//
//  Application settings
//
    QString
        strDatabaseSection = "Database",            // Database section name
        strKeyDbServerName = "DatabaseServerName",  // Key name with database server name
        strDatabaseServerNameDef = "localhost",     // Default database server
        strDatabaseServerName,                      // Database server name
        //-------------------------------------------------------------------------------
        strKeyDbName = "DatabaseName",              // Key name with database name
        strDatabaseNameDef = "vmdevdb01",           // Default database name
        strDatabaseName,                            // Database name
        //-------------------------------------------------------------------------------
        strTemp;

};

#endif // MAINWINDOW_H
