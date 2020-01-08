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

private:
    Ui::MainWindow *ui;

    euDatabase *Database;

    QString
       strTemp;

};

#endif // MAINWINDOW_H
