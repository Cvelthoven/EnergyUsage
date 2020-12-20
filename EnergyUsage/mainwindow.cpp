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
#include <QMenu>
#include <QMenuBar>
#include <QString>

//---------------------------------------------------------------------------------------
//
//  Application specific include files
//
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "energyusage.h"
#include "applicationsettingsmodel.h"
#include "applicationlogging.h"
#include "energyusagedatamodel.h"
#include "energyusagedatabase.h"

#include <QDebug>

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
    AppSettings = new ApplicationSettingsModel;

//    if (!InitializeProgram())
//    {
//       exit(0);
//    }

    //-----------------------------------------------------------------------------------
    //
    //  Actual program run
    //  and load startup page values
    //
    ui->setupUi(this);
    if (!retrieveDbLogSettings())
    {
        goExit();
    }
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
    //  Setup mainwindow gui
//    setupMenuBar();


    //---------------------------------------------------------------------------------------
    //
    //  Start application logging
    strSeverity = "Info";
    strMessage  = "EnergyUsage started";
    QDateTime euStartTime = QDateTime::currentDateTime();
    AppLogging = new ApplicationLogging(this);
    if (AppLogging->bDBconnected)
        bAppLogConnected = true;
    else
        exit(0);
     AppLogging->WriteLogRecord(&euStartTime,&strSeverity,&strMessage);

    //---------------------------------------------------------------------------------------
    //
    //  Connect to database
    Database = new EnergyUsageDatabase(this, AppLogging);
    if (Database->bDBconnected)
        bDatabaseConnected = true;
    else
        exit(0);

    return true;
}


//---------------------------------------------------------------------------------------
//
//  Proceduce: setupMenuBar
//
void MainWindow::setupMenuBar()
{
    QMenu *menu = menuBar()->addMenu(tr("Test menu"));
    // = menuBar()->addMenu(tr("Test menu"));
    menu->addAction(tr("test exit"),this,&MainWindow::on_actionExit_triggered);

}


//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//
//  Main menu slot functions
//
//---------------------------------------------------------------------------------------
//
//  File -> exit
//
void MainWindow::on_actionExit_triggered()
{
    goExit();
}


//---------------------------------------------------------------------------------------
//
//  File -> Open Import -> Gas
//
void MainWindow::on_actionGas_triggered()
{
    strTemp = "gas";
    strImportFileName = QFileDialog::getOpenFileName(this,tr("Gas metrics import file"));
    if (strImportFileName.length() != 0)
        Database->ImportMetricsFile(&strTemp,&strImportFileName);

}


//---------------------------------------------------------------------------------------
//
//  File -> Open Import -> Electricity
//
void MainWindow::on_actionElectricity_triggered()
{
    strTemp = "elec";
    strImportFileName = QFileDialog::getOpenFileName(this,tr("Electricity metrics import file"));
    if (strImportFileName.length() != 0)
        Database->ImportMetricsFile(&strTemp,&strImportFileName);

}


//---------------------------------------------------------------------------------------
//
//  File -> Open Import -> Water
//
void MainWindow::on_actionWater_triggered()
{
    strTemp = "water";
    strImportFileName = QFileDialog::getOpenFileName(this,tr("Water metrics import file"));
    if (strImportFileName.length() != 0)
        Database->ImportMetricsFile(&strTemp,&strImportFileName);

}

//---------------------------------------------------------------------------------------
//
//  Options -> Database
//
void MainWindow::on_actionDatabase_triggered()
{
    qDebug() << "Options->Database triggered";


}


//---------------------------------------------------------------------------------------
//
//  MainWindow general functions
//
//---------------------------------------------------------------------------------------
//
//  Function: goExit
//      Clean up
//      Close databases
//      go exit
//
void MainWindow::goExit()
{
    if (bAppLogConnected)
    {
        strSeverity = "Info";
        strMessage  = "EnergyUsage ended normal";
        AppLogging->WriteLogRecord(&strSeverity,&strMessage);
        delete AppLogging;
    }
    if (bDatabaseConnected)
        delete Database;
    exit(0);

}


//---------------------------------------------------------------------------------------
//
//  retrieveDbLogSettings
//      Retrieve settings defined in the application configuration for:
//      -   application database
//      -   application logging
bool MainWindow::retrieveDbLogSettings()
{
//    int iStrLen;
    //-----------------------------------------------------------------------------------
    //
    //  Retrieve application database settings and load them in startup window
//    AppSettings = new ApplicationSettingsModel;
//    strAppDatabaseServerName = AppSettings->GetAppSetting(strAppDbSectionName,strAppKeyDbServerName);
//    iStrLen = strAppDatabaseServerName.length();
//    if (iStrLen != 0)
//        ui->applicationServerLineEdit->insert(strAppDatabaseServerName);

//    strAppDatabaseName       = AppSettings->GetAppSetting(strAppDbSectionName,strAppKeyDbName);
//    iStrLen = strAppDatabaseName.length();
//    if (iStrLen != 0)
//        ui->applicationDatabaseLineEdit->insert(strAppDatabaseName);

//    strAppDatabaseUserId     = AppSettings->GetAppSetting(strAppDbSectionName,strAppKeyDbUserId);
//    iStrLen = strAppDatabaseUserId.length();
//    if (iStrLen != 0)
//        ui->applicationDatabaseUseridLineEdit->insert(strAppDatabaseUserId);

//    strAppDatabasePassword   = AppSettings->GetAppSetting(strAppDbSectionName,strAppKeyDbPassword);
//    iStrLen = strAppDatabasePassword.length();
//    if (iStrLen != 0)
//        ui->applicationDatabasePasswordLineEdit->insert(strAppDatabasePassword);

//    //-----------------------------------------------------------------------------------
//    //
//    //  Retrieve logging settings and load them in startup window
//    strAppLogDatabaseServerName = AppSettings->GetAppSetting(strAppLogSectionName,strAppLogKeyDbServerName);
//    iStrLen = strAppLogDatabaseServerName.length();
//    if (iStrLen != 0)
//        ui->loggingServerLineEdit->insert(strAppLogDatabaseServerName);

//    strAppLogDatabaseName       = AppSettings->GetAppSetting(strAppLogSectionName,strAppLogKeyDbName);
//    iStrLen = strAppLogDatabaseName.length();
//    if (iStrLen != 0)
//        ui->loggingDatabaseLineEdit->insert(strAppLogDatabaseName);

//    strAppLogDatabaseUserId     = AppSettings->GetAppSetting(strAppLogSectionName,strAppLogKeyDbUserId);
//    iStrLen = strAppLogDatabaseUserId.length();
//    if (iStrLen != 0)
//        ui->loggingUseridLineEdit->insert(strAppLogDatabaseUserId);

//    strAppLogDatabasePassword   = AppSettings->GetAppSetting(strAppLogSectionName,strAppLogKeyDbPassword);
//    iStrLen = strAppLogDatabasePassword.length();
//    if (iStrLen != 0)
//        ui->loggingPasswordLineEdit->insert(strAppLogDatabasePassword);


    return true;
}


//---------------------------------------------------------------------------------------
//
//  Events
//
//---------------------------------------------------------------------------------------


