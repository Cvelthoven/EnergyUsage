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

//-----------------------------------------------------------------------------
//
//  Application settings
//  Temp default set
    QString
        strAplSetDbServerName = "DatabaseName",
        strDatabaseServerName = "localhost",
        strTemp;

};

#endif // MAINWINDOW_H
