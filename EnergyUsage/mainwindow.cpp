//---------------------------------------------------------------------------------------
//
//  Program : EnergyUsage
//  Module  : mainwindow
//
//---------------------------------------------------------------------------------------
//
//  General include files
#include <QString>

//---------------------------------------------------------------------------------------
//
//  Application specific include files
//
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "euapplicationsettings.h"

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
    //
    //  Set application name information and create application wide objects
    ApplicationSettings = new euApplicationSettings();
    //-----------------------------------------------------------------------------------
    //
    // Initialize the program
    if (!InitializeProgram())
    {
       exit(0);
    }
    Database = new euDatabase;


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

    int iStrlen;


    //-----------------------------------------------------------------------------------
    //
    //  Get datbase configuration
    strDatabaseServerName = ApplicationSettings->euGetAppSetting(strDatabaseSection, strKeyDbServerName);
    iStrlen = strDatabaseServerName.length();
    if (iStrlen == 0)
    {
        bOk = ApplicationSettings->euSetAppSetting(strDatabaseSection,strKeyDbServerName,strDatabaseServerNameDef);
    }
    strDatabaseName = ApplicationSettings->euGetAppSetting(strDatabaseSection, strKeyDbName);
    iStrlen = strDatabaseName.length();
    if (iStrlen == 0)
    {
        bOk = ApplicationSettings->euSetAppSetting(strDatabaseSection,strKeyDbName,strDatabaseNameDef);
    }
    return bOk;
}

