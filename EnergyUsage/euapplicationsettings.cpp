//---------------------------------------------------------------------------------------
//
//  flrApplicationSettings
//
//  Retrieve and maintain application settings
#include "euapplicationsettings.h"

#include <QCoreApplication>
#include <QSettings>
#include <QString>

//---------------------------------------------------------------------------------------
//
//  Default contructor
//
//flrApplicationSettings::flrApplicationSettings(QObject *parent)
euApplicationSettings::euApplicationSettings()
{
    //-----------------------------------------------------------------------------------
    //
    //  Set application environment definitions
    //
    QCoreApplication::setOrganizationName("CVelthoven");
    QCoreApplication::setOrganizationDomain("CVelthoven.com");
    QCoreApplication::setApplicationName("EnergyUsage");

}

//---------------------------------------------------------------------------------------
//
//  flrGetAppSetting
//
//  retrieve application setting value
//
QString euApplicationSettings::euGetAppSetting(const QString &strSettingName)
{

    QSettings programDefaults;
    QVariant temp = programDefaults.value(strSettingName);
    if (temp.isValid())
    {
        QString strSettingValue = temp.toString();
        return strSettingValue;
    }
    return "";
}

//---------------------------------------------------------------------------------------
//
//  flrsetAppSetting
//
//  save application setting value
//
bool euSetAppSetting(const QString *strSettingName, const QString *strSettingValue)
{

    QSettings programDefaults;
    programDefaults.setValue(*strSettingName,*strSettingValue);
    return(0);
}
