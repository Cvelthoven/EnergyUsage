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
    //  Setup mainwindow gui
//    setupMenuBar();


    //---------------------------------------------------------------------------------------
    //
    //  Start application logging
    strSeverity = "Info";
    strMessage  = "EnergyUsage started";
    QDateTime euStartTime = QDateTime::currentDateTime();
    AppLogging = new ApplicationLogging(this);
    if (!AppLogging->bDBconnected)
    {
        exit(0);
    }
    AppLogging->WriteLogRecord(&euStartTime,&strSeverity,&strMessage);

    //---------------------------------------------------------------------------------------
    //
    //  Connect to database
    Database = new EnergyUsageDatabase(this, AppLogging);
    if (!Database->bDBconnected)
    {
        exit(0);
    }

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
//
//  Main menu slot functions
//
//  File -> exit
//
void MainWindow::on_actionExit_triggered()
{
    strSeverity = "Info";
    strMessage  = "EnergyUsage ended normal";
    AppLogging->WriteLogRecord(&strSeverity,&strMessage);
    delete AppLogging;
    delete Database;
    exit(0);

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


////---------------------------------------------------------------------------------------
////
////  DatabaseView activated
////
//void MainWindow::on_tbvDatabaseView_activated(const QModelIndex &index)
//{
//    ui->tbvDatabaseView->setRootIndex(index);
//}

////---------------------------------------------------------------------------------------
////
//// TestLineEdit actions
////
//void MainWindow::on_TestLineEdit_cursorPositionChanged(int arg1, int arg2)
//{
//    qDebug("arg1: %i",arg1);
//    qDebug("arg2: %i",arg2);
//}

//void MainWindow::on_TestLineEdit_returnPressed()
//{
//    ui->TestLineEdit->setPlaceholderText("test line");
//    ui->TestLineEdit->setFocus();
//    QString test = ui->TestLineEdit->text();
//    qDebug() << "Test string: " << test;

//}


