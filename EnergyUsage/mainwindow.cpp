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

    //---------------------------------------------------------------------------------------
    //
    //  Start application logging
    ApplicationLog = new euApplicationLogging(this);
    //---------------------------------------------------------------------------------------
    //
    //  Connect to database
    QDateTime euStartTime = QDateTime::currentDateTime();
    Database = new euDatabase(this);

    return bOk;
}

