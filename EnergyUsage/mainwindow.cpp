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
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
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

    if (!InitializeProgram())
    {
       exit(0);
    }

    //-----------------------------------------------------------------------------------
    //
    //  Actual program run
    //  and load startup page values
    //
    ui->setupUi(this);
    ui->statusBar->addWidget(statusApplication,0);
    ui->statusBar->insertWidget(1,statusAplDb,0);
    ui->statusBar->insertWidget(2,statusLogging,0);
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
    //  Start application
    //
    //  Retrieve current date time and setup startup logging record
    QDateTime aplStartTime = QDateTime::currentDateTime();
    strSeverity = "Info";
    strMessage  = "EnergyUsage started";

    //-----------------------------------------------------------------------------------
    //
    //  Set statusbar fields to startup values
    statusApplication = new QLabel();
    statusApplication->setText("Starting");
    statusApplication->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    statusAplDb = new QLabel();
    statusAplDb->setText("Database: not connected");
    statusAplDb->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    statusLogging = new QLabel();
    statusLogging->setText("Logging: not connected");
    statusLogging->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    //-----------------------------------------------------------------------------------
    //
    //  Set statusbar fields to startup values
    ApplicationSettingsModel *tempAplSettings = new ApplicationSettingsModel();
    strAppLogDatabaseName = tempAplSettings->GetAppSetting(strAppLogSectionName,strAppLogKeyDbName);

    //-----------------------------------------------------------------------------------
    //
    //  Connect logging database
    //
    if (inititializeLogging())
    {
        //-------------------------------------------------------------------------------
        //
        //  Write application start time to log
        AppLogging->WriteLogRecord(&aplStartTime,&strSeverity,&strMessage);

        //-------------------------------------------------------------------------------
        //
        //  Write application database logging connection time to log
        aplStartTime = QDateTime::currentDateTime();
        strSeverity = "Info";
        strMessage  = "Application logging: " + strAppLogDatabaseName + " connected";
        AppLogging->WriteLogRecord(&aplStartTime,&strSeverity,&strMessage);
   }
    else
        return false;


    //-----------------------------------------------------------------------------------
    //
    //  Connect to database
    strAppDatabaseName = tempAplSettings->GetAppSetting(strDatabaseSection,strKeyDbName);
    if (inititializeAppDatabase())
    {
        aplStartTime = QDateTime::currentDateTime();
        strSeverity = "Info";
        strMessage  = "Application database: " + strAppDatabaseName + " ready";
        AppLogging->WriteLogRecord(&aplStartTime,&strSeverity,&strMessage);
    }
    else
    {
        aplStartTime = QDateTime::currentDateTime();
        strSeverity = "Error";
        strMessage  = "Application database: " + strAppDatabaseName + " failed";
        AppLogging->WriteLogRecord(&aplStartTime,&strSeverity,&strMessage);
        return false;
    }

    //-----------------------------------------------------------------------------------
    //
    //  Succesfull initialization
    statusApplication->setText("Ready");
    return true;
}


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
//  Tools -> Configuration
//
void MainWindow::on_actionConfiguration_triggered()
{
    qDebug() << "Tools -> Configuration triggered";
    ApplicationSettings = new ApplicationSettingsView;
}

//---------------------------------------------------------------------------------------


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
//  inititializeAppDatabase
//
bool MainWindow::inititializeAppDatabase()
{
    //-----------------------------------------------------------------------------------
    //
    //  Initialize EnergyUsageDataModel
    ApllicationDatabase = new EnergyUsageDataModel(this, AppLogging);

    return false;
//----------- original code -------------------------------------------------------------
//    Database = new EnergyUsageDatabase(this, AppLogging);
//    if (Database->bDBconnected)
//    {
//        strTemp = "Application database: " + strAppLogDatabaseName;
//        statusAplDb->setText(strTemp);
//        statusAplDb->setStyleSheet("color:green");
//        bDatabaseConnected = true;
//        return true;
//    }
//    //-----------------------------------------------------------------------------------
//    //
//    //  Enable user to set the logging configuration or go exit
//    //  Needs to be built
//    else
//    {
//        strTemp = "Application database: " + strAppLogDatabaseName;
//        statusAplDb->setText(strTemp);
//        statusAplDb->setStyleSheet("color:red");
//        bAppLogConnected = false;
//        //
//        // ----  Allow the user to set the application database configuration at startup
//        //
//        return false;
//    }
}

//---------------------------------------------------------------------------------------
//
//  InititializeLogging
//
bool MainWindow::inititializeLogging()
{

    AppLogging = new ApplicationLogging(this);
    if (AppLogging->bDBconnected)
    {
        strTemp = "Logging: " + strAppLogDatabaseName;
        statusLogging->setText(strTemp);
        statusLogging->setStyleSheet("color:green");
        bAppLogConnected = true;
        return true;
    }

    //-----------------------------------------------------------------------------------
    //
    //  Enable user to set the logging configuration or go exit
    //  Needs to be built
    else
    {
        strTemp = "Logging: " + strAppLogDatabaseName;
        statusLogging->setText(strTemp);
        statusLogging->setStyleSheet("color:red");
        bAppLogConnected = false;
        //
        // ----  Allow the user to set the logging configuration at startup
        //
        return false;
    }
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
//    ApplicationSettings = new ApplicationSettingsView;
//    strAppDatabaseServerName = ApplicationSettings->GetAppSetting(strAppDbSectionName,strAppKeyDbServerName);
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



