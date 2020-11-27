//---------------------------------------------------------------------------------------
//
//  ApplicationSettingsModel
//
//  Model class containing, handling the application settings
//
//  Location of configuration file linux: home/.config/Cvelthoven
//
#ifndef ApplicationSettingsModel_H
#define ApplicationSettingsModel_H

#include <QObject>
#include <QWidget>

#include <QString>

class ApplicationSettingsModel
{
public:
    ApplicationSettingsModel();
    QString GetAppSetting(const QString &strSettingSection, const QString &strSettingName);
    bool SetAppSetting(const QString &strSettingSection, const QString &strSettingName, const QString &strSettingValue);

private:
    QString strFullKeyPath;
};

#endif // ApplicationSettingsModel_H
