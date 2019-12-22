//---------------------------------------------------------------------------------------
//
//  flrApplicationSettings
//
//  Retrieve and maintain application settings
//
//  Location of configuration file linux: home/.config/Cvelthoven
//
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
//  Input:
//      strSettingSection: section name of the key
//      strSettingName   : key name
//  Ouptut:
//      euGetAppSetting  : value of key if found otherwise and empty string
//
QString euApplicationSettings::euGetAppSetting(const QString &strSettingSection, const QString &strSettingName)
{

    QSettings programDefaults;

    if (strSettingSection.size() != 0)
        strFullKeyPath = strSettingSection + "//" + strSettingName;
    else
        strFullKeyPath = strSettingName;

    QVariant temp = programDefaults.value(strFullKeyPath);
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
bool euApplicationSettings::euSetAppSetting(const QString &strSettingSection, const QString &strSettingName, const QString &strSettingValue)
{
    if (strSettingSection.size() != 0)
        strFullKeyPath = strSettingSection + "//" + strSettingName;
    else
        strFullKeyPath = strSettingName;

    QSettings programDefaults;
    programDefaults.setValue(strFullKeyPath,strSettingValue);
    return(true);
}
