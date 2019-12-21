#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

#include "euapplicationsettings.h"
#include "eudatabase.h"
#include "eulogfile.h"

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

    bool InitializeProgram();

private:
    Ui::MainWindow *ui;

    euDatabase *Database;
    euLogFile *Logfile;

//---------------------------------------------------------------------------------------
//
//  Application settings
//
    QString
       strTemp;

};

#endif // MAINWINDOW_H
