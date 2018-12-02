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
    InitializeProgram();

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
void MainWindow::InitializeProgram()
{
    //-----------------------------------------------------------------------------------
    //
    //  Local variables
    bool bOk;

    int iStrlen;

    QString
        strDatabaseServerNameDef = "localhost";

    //-----------------------------------------------------------------------------------
    //
    //  Set application name information and create application wide objects
    ApplicationSettings = new euApplicationSettings();

    //-----------------------------------------------------------------------------------
    //
    //
    strDatabaseServerName = ApplicationSettings->euGetAppSetting(strAplSetDbServerName);
    iStrlen = strDatabaseServerName.length();
    if (iStrlen == 0)
    {
        bOk = ApplicationSettings->euSetAppSetting(strAplSetDbServerName,strDatabaseServerNameDef);
    }
}

