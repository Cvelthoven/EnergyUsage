#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

#include "euapplicationsettings.h"
#include "euapplicationlogging.h"
#include "eudatabase.h"

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

private:
    Ui::MainWindow *ui;

    euDatabase *Database;

    QString
        strTemp,
        strSeverity,
        strMessage;

};

#endif // MAINWINDOW_H
