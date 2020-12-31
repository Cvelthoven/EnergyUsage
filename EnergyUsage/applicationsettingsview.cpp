//---------------------------------------------------------------------------------------
//
//  EnergyUsage: applicationsettingsdialog
//
//---------------------------------------------------------------------------------------
//
//  General QT header files
#include <QList>
#include <QString>
#include <QStringList>

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
    //-----------------------------------------------------------------------------------
    //
    //  local variables
    //
    int iCnt;

    QString strTempSectionName,
            strTempSettingName,
            strTempSettingValue;
    QStringList strListTemp;

    //-----------------------------------------------------------------------------------
    //
    //  Initialise aplConfigurationList and retrieve configured application settings
    //
    AplConfiguration = new ApplicationSettingsModel();
    strTempSectionName = "AplDatabase";
    for (iCnt = 0; iCnt < 4; iCnt++)
    {
        switch (iCnt)
        {

            case 0:
                strTempSettingName = "AplDatabaseServerName";
                break;
            case 1:
                strTempSettingName = "AplDatabaseName";
                break;
            case 2:
                strTempSettingName = "AplDatabaseUserId";
                break;
            case 3:
                strTempSettingName = "AplDatabasePassword";
                break;
        }
        strTempSettingValue = AplConfiguration->GetAppSetting(strTempSectionName,strTempSettingName);
        strListTemp << strTempSettingName << strTempSettingValue;
        aplConfigurationList.append(strListTemp);
        strListTemp.clear();
    }

    strTempSectionName = "Log";
    for (iCnt = 0; iCnt < 4; iCnt++)
    {
        switch (iCnt)
        {

            case 0:
                strTempSettingName = "LogDatabaseServerName";
                break;
            case 1:
                strTempSettingName = "LogDatabaseName";
                break;
            case 2:
                strTempSettingName = "LogDatabaseUserId";
                break;
            case 3:
                strTempSettingName = "LogDatabasePassword";
                break;
        }
        strTempSettingValue = AplConfiguration->GetAppSetting(strTempSectionName,strTempSettingName);
        strListTemp << strTempSettingName << strTempSettingValue;
        aplConfigurationList.append(strListTemp);
        strListTemp.clear();
    }

    //-----------------------------------------------------------------------------------
    //
    //  Create and load dialog
    //
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
