//---------------------------------------------------------------------------------------
//
//  Program : EnergyUsage
//  Module  : mainwindow
//
//---------------------------------------------------------------------------------------
//
//  General include files
#include <QDateTime>
#include <QString>

//---------------------------------------------------------------------------------------
//
//  Application specific include files
//
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "euapplicationsettings.h"
#include "euapplicationlogging.h"

//---------------------------------------------------------------------------------------
//
//  Proceduce: MainWindow constructor
//
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //-----------------------------------------------------------------------------------
    //
    //  Program initialization
    //
    //-----------------------------------------------------------------------------------
    if (!InitializeProgram())
    {
       exit(0);
    }

    ui->setupUi(this);
}
//---------------------------------------------------------------------------------------
//
//  Proceduce: MainWindow destructor
//
MainWindow::~MainWindow()
{
    delete ui;
}

//---------------------------------------------------------------------------------------
//
//  Proceduce: InitializeProgram
//
bool MainWindow::InitializeProgram()
{
    //-----------------------------------------------------------------------------------
    //
    //  Local variables
    bool bOk = false;
    QString
        strSeverity     = "info",
        strMessage      = "Program started";

    //---------------------------------------------------------------------------------------
    //
    //  Start application logging
    QDateTime euStartTime = QDateTime::currentDateTime();
    ApplicationLog = new euApplicationLogging(this);
    ApplicationLog->WriteLogRecord(&euStartTime,&strSeverity,&strMessage);

    //---------------------------------------------------------------------------------------
    //
    //  Connect to database
    Database = new euDatabase(this);

    return bOk;
}

