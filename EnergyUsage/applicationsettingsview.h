#ifndef APPLICATIONSETTINGSVIEW_H
#define APPLICATIONSETTINGSVIEW_H

#include <QDialog>

namespace Ui {
class ApplicationSettingsView;
}

class ApplicationSettingsView : public QDialog
{
    Q_OBJECT

public:
    explicit ApplicationSettingsView(QWidget *parent = nullptr);
    ~ApplicationSettingsView();

private:
    Ui::ApplicationSettingsView *ui;
};

#endif // APPLICATIONSETTINGSVIEW_H
