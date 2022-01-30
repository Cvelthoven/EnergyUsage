//---------------------------------------------------------------------------------------
//
//  ApplicationSettingsModel
//
//  Model class containing and handling the application settings
//
//  Location of configuration file linux: home/.config/Cvelthoven
//
#include "applicationsettingsmodel.h"
#include "energyusage.h"

#include <QCoreApplication>
#include <QSettings>

//---------------------------------------------------------------------------------------
//
//  Default contructor
//
ApplicationSettingsModel::ApplicationSettingsModel()
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
//  GetAppSetting
//
//  retrieve application setting value
//
//  Input:
//      strSettingSection: section name of the key
//      strSettingName   : key name
//  Ouptut:
//      euGetAppSetting  : value of key if found otherwise and empty string
//
QString ApplicationSettingsModel::GetAppSetting(const QString &strSettingSection,
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
//  SetAppSetting
//
//  save application setting value
//
bool ApplicationSettingsModel::SetAppSetting(const QString &strSettingSection,
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
