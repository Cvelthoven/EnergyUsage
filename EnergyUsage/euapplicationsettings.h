#ifndef EUAPPLICATIONSETTINGS_H
#define EUAPPLICATIONSETTINGS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class euApplicationSettings
{
public:
//    flrApplicationSettings(QObject *parent);
    euApplicationSettings();
    QString euGetAppSetting(const QString &strSettingSection, const QString &strSettingName);
    bool euSetAppSetting(const QString &strSettingSection, const QString &strSettingName, const QString &strSettingValue);

private:
    QString strFullKeyPath;

};

#endif // EUAPPLICATIONSETTINGS_H
