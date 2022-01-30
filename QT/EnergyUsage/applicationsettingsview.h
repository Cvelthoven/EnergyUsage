#ifndef APPLICATIONSETTINGSVIEW_H
#define APPLICATIONSETTINGSVIEW_H
//---------------------------------------------------------------------------------------
//
//  General QT header files
#include <QDialog>
#include <QList>
#include <QStringList>

//---------------------------------------------------------------------------------------
//
// EnergyUsage specific header files
#include "applicationsettingsmodel.h"

namespace Ui {
class ApplicationSettingsView;
}

class ApplicationSettingsView : public QDialog
{
    Q_OBJECT

public:
    explicit ApplicationSettingsView(QWidget *parent = nullptr);
    ~ApplicationSettingsView();

private slots:
    void on_btnConfig_accepted();

private:
    Ui::ApplicationSettingsView *ui;

    ApplicationSettingsModel *AplConfiguration;

    QList<QStringList> aplConfigurationList;
};

#endif // APPLICATIONSETTINGSVIEW_H
