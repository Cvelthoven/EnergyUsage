//---------------------------------------------------------------------------------------
//
//  flrApplicationSettings
//
//  Retrieve and maintain application settings
//
//  Location of configuration file linux: home/.config/Cvelthoven
//
#include "applicationsettings.h"
#include "energyusage.h"

#include <QCoreApplication>
#include <QSettings>
#include <QString>

//---------------------------------------------------------------------------------------
//
//  Default contructor
//
//flrApplicationSettings::flrApplicationSettings(QObject *parent)
ApplicationSettings::ApplicationSettings()
{
    //-----------------------------------------------------------------------------------
    //
    //  Set application environment definitions
    //
    QCoreApplication::setOrganizationName(strOrganizationName);
    QCoreApplication::setOrganizationDomain(strOrganizationDomain);
    QCoreApplication::setApplicationName(strApplicationName);

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
QString ApplicationSettings::GetAppSetting(const QString &strSettingSection,
                                               const QString &strSettingName)
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
bool ApplicationSettings::SetAppSetting(const QString &strSettingSection,
                                            const QString &strSettingName,
                                            const QString &strSettingValue)
{
    if (strSettingSection.size() != 0)
        strFullKeyPath = strSettingSection + "//" + strSettingName;
    else
        strFullKeyPath = strSettingName;

    QSettings programDefaults;
    programDefaults.setValue(strFullKeyPath,strSettingValue);
    return(true);
}
