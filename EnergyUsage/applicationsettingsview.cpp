//---------------------------------------------------------------------------------------
//
//  EnergyUsage: applicationsettingsdialog
//
//---------------------------------------------------------------------------------------
//
//  General QT header files

//---------------------------------------------------------------------------------------
//
// EnergyUsage specific header files
#include "energyusage.h"
#include "applicationsettingsmodel.h"
#include "applicationsettingsview.h"
#include "ui_applicationsettingsview.h"

//---------------------------------------------------------------------------------------
// Debugging include
#include <QDebug>

//---------------------------------------------------------------------------------------
//
//  ApplicationSettingsView dialog constructor
//
ApplicationSettingsView::ApplicationSettingsView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ApplicationSettingsView)
{
    qDebug() << "Settings dialog -> constructor triggered";
    AplConfiguration = new ApplicationSettingsModel;
    ui->setupUi(this);
    ApplicationSettingsView::exec();
}

//---------------------------------------------------------------------------------------
//
//  ApplicationSettingsView dialog destructor
//
ApplicationSettingsView::~ApplicationSettingsView()
{
    delete ui;
}


//---------------------------------------------------------------------------------------
//
//  ApplicationSettingsView slots
//
void ApplicationSettingsView::on_btnConfig_accepted()
{
    qDebug() << "Settings dialog -> config accepted slot triggered";

}
