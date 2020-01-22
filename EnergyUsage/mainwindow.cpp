//---------------------------------------------------------------------------------------
//
//  Program : EnergyUsage
//  Module  : mainwindow
//
//---------------------------------------------------------------------------------------
//
//  General include files
#include <QDateTime>
#include <QFileDialog>
#include <QString>

//---------------------------------------------------------------------------------------
//
//  Application specific include files
//
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "energyusage.h"
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
    if (!InitializeProgram())
    {
       exit(0);
    }

    //-----------------------------------------------------------------------------------
    //
    //  Actual program run
    //
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
//    bool bOk = false;

    //---------------------------------------------------------------------------------------
    //
    //  Start application logging
    strSeverity = "Info";
    strMessage  = "EnergyUsage started";
    QDateTime euStartTime = QDateTime::currentDateTime();
    ApplicationLog = new euApplicationLogging(this);
    if (!ApplicationLog->bDBconnected)
    {
        exit(0);
    }
    ApplicationLog->WriteLogRecord(&euStartTime,&strSeverity,&strMessage);

    //---------------------------------------------------------------------------------------
    //
    //  Connect to database
    Database = new euDatabase(this, ApplicationLog);
    if (!Database->bDBconnected)
    {
        exit(0);
    }

    return true;
}

//---------------------------------------------------------------------------------------
//
//  Main menu slot functions
//
//  File -> exit
//
void MainWindow::on_actionExit_triggered()
{
    strSeverity = "Info";
    strMessage  = "EnergyUsage ended normal";
    ApplicationLog->WriteLogRecord(&strSeverity,&strMessage);
    delete ApplicationLog;
    exit(0);

}

//---------------------------------------------------------------------------------------
//
//  File -> Open Import -> Gas
//
void MainWindow::on_actionGas_triggered()
{
    strGasImportFileName = QFileDialog::getOpenFileName(this,tr("Gas metrics import file"));
    if (strGasImportFileName.length() != 0)
        strTemp = strGasImportFileName;
}
