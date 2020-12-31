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
    AplConfiguration = new ApplicationSettingsModel;
    ui->setupUi(this);
    for (iCnt = 0; iCnt < 8; iCnt++)
    {
        switch (iCnt)
        {
            //---------------------------------------------------------------------------
            //
            //  Switch to application section of configuration
            case 0:
                strTempSectionName = "AplDatabase";
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
            //---------------------------------------------------------------------------
            //
            //  Switch to log section of configuration
            case 4:
                strTempSectionName = "Log";
                strTempSettingName = "LogDatabaseServerName";
                break;
            case 5:
                strTempSettingName = "LogDatabaseName";
                break;
            case 6:
                strTempSettingName = "LogDatabaseUserId";
                break;
            case 7:
                strTempSettingName = "LogDatabasePassword";
                break;
        }
        strTempSettingValue = AplConfiguration->GetAppSetting(strTempSectionName,strTempSettingName);
        strListTemp << strTempSettingName << strTempSettingValue;
        aplConfigurationList.append(strListTemp);
        strListTemp.clear();

        //---------------------------------------------------------------------------
        //
        //  Load found settings to dialog
        switch (iCnt)
        {
            case 0:
                ui->lnAplDatabaseServer->setText(strTempSettingValue);
                break;
            case 1:
                ui->lnAplDatabase->setText(strTempSettingValue);
                break;
            case 2:
                ui->lnAplUserID->setText(strTempSettingValue);
                break;
            case 3:
                ui->lnAplPassword->setText(strTempSettingValue);
                break;
            case 4:
                ui->lnLogLoggingServer->setText(strTempSettingValue);
                break;
            case 5:
                ui->lnLogLoggingDatabase->setText(strTempSettingValue);
                break;
            case 6:
                ui->lnLogUserId->setText(strTempSettingValue);
                break;
            case 7:
                ui->lnLogPassword->setText(strTempSettingValue);
                break;
        }
    }

    //-----------------------------------------------------------------------------------
    //
    //  Execute dialog
    //
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
