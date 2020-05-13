#ifndef EUAPPLICATIONSETTINGS_H
#define EUAPPLICATIONSETTINGS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class ApplicationSettings
{
public:
//    flrApplicationSettings(QObject *parent);
    ApplicationSettings();
    QString GetAppSetting(const QString &strSettingSection, const QString &strSettingName);
    bool SetAppSetting(const QString &strSettingSection, const QString &strSettingName, const QString &strSettingValue);

private:
    QString strFullKeyPath;

};

#endif // EUAPPLICATIONSETTINGS_H
