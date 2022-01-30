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
    //-----------------------------------------------------------------------------------
    //
    //  local variables
    //
    bool
            bAplConfigChanged = false,
            bLogConfigChanged = false;
    int iCnt1;

    QString
            strSectionName,
            strTemp;
    QStringList strListTemp;

    qDebug() << "Settings dialog -> config accepted slot triggered";

    //-----------------------------------------------------------------------------------
    //
    //  Verify values are changed and update the application configuration
    for (iCnt1=0; iCnt1 < 8; iCnt1++)
    {
        strListTemp = aplConfigurationList[iCnt1];
        switch (iCnt1)
        {
            //---------------------------------------------------------------------------
            //
            //  Switch to application section of configuration
            case 0:
                strSectionName = "AplDatabase";
                strTemp = ui->lnAplDatabaseServer->text();
                break;
            case 1:
                strTemp = ui->lnAplDatabase->text();
                break;
            case 2:
                strTemp = ui->lnAplUserID->text();
                break;
            case 3:
                strTemp = ui->lnAplPassword->text();
                break;
            //---------------------------------------------------------------------------
            //
            //  Switch to log section of configuration
            case 4:
                strSectionName = "Log";
                strTemp = ui->lnLogLoggingServer->text();
                break;
            case 5:
                strTemp = ui->lnLogLoggingDatabase->text();
                break;
            case 6:
                strTemp = ui->lnLogUserId->text();
                break;
            case 7:
                strTemp = ui->lnLogPassword->text();
                break;

        }

        //-------------------------------------------------------------------------------
        //
        //  Update application configuration when value is changed
        if (strListTemp[1] != strTemp)
        {
            AplConfiguration->SetAppSetting(strSectionName,strListTemp[0],strTemp);
            if (iCnt1 < 4)
                bAplConfigChanged = true;
            else
                bLogConfigChanged = true;
        }
    }
    if (bAplConfigChanged)
    {
        qDebug() << "Signal to applicationmodel that application configuration is changed";
    }
    if (bLogConfigChanged)
    {
        qDebug() << "Signal to applicationmodel that logging configuration is changed";

    }
}
