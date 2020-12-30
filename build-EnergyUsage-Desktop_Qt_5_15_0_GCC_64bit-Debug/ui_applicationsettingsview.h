/********************************************************************************
** Form generated from reading UI file 'applicationsettingsview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLICATIONSETTINGSVIEW_H
#define UI_APPLICATIONSETTINGSVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ApplicationSettingsView
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabApplicationConfiguration;
    QWidget *tabApplicationDbConfiguration;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formApplicationDbConfiguration;
    QLabel *lblAplDatabaseServer;
    QLineEdit *lnAplDatabaseServer;
    QLabel *lblAplDatabase;
    QLineEdit *lnAplDatabase;
    QLabel *lblAplUserID;
    QLineEdit *lnAplUserID;
    QLabel *lblAplPassword;
    QLineEdit *lnAplPassword;
    QWidget *tabLoggingConfiguration;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLoggingConfiguration;
    QLabel *lblLogLogging;
    QLineEdit *lnLogLoggingServer;
    QLabel *lblLogLoggingDatabase;
    QLineEdit *lnLogLoggingDatabase;
    QLabel *lblLogUserId;
    QLineEdit *lnLogUserId;
    QLabel *lblLogPassword;
    QLineEdit *lnLogPassword;
    QDialogButtonBox *btnConfig;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *ApplicationSettingsView)
    {
        if (ApplicationSettingsView->objectName().isEmpty())
            ApplicationSettingsView->setObjectName(QString::fromUtf8("ApplicationSettingsView"));
        ApplicationSettingsView->resize(511, 264);
        verticalLayout = new QVBoxLayout(ApplicationSettingsView);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabApplicationConfiguration = new QTabWidget(ApplicationSettingsView);
        tabApplicationConfiguration->setObjectName(QString::fromUtf8("tabApplicationConfiguration"));
        tabApplicationDbConfiguration = new QWidget();
        tabApplicationDbConfiguration->setObjectName(QString::fromUtf8("tabApplicationDbConfiguration"));
        verticalLayout_2 = new QVBoxLayout(tabApplicationDbConfiguration);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        formApplicationDbConfiguration = new QFormLayout();
        formApplicationDbConfiguration->setObjectName(QString::fromUtf8("formApplicationDbConfiguration"));
        formApplicationDbConfiguration->setVerticalSpacing(4);
        lblAplDatabaseServer = new QLabel(tabApplicationDbConfiguration);
        lblAplDatabaseServer->setObjectName(QString::fromUtf8("lblAplDatabaseServer"));

        formApplicationDbConfiguration->setWidget(0, QFormLayout::LabelRole, lblAplDatabaseServer);

        lnAplDatabaseServer = new QLineEdit(tabApplicationDbConfiguration);
        lnAplDatabaseServer->setObjectName(QString::fromUtf8("lnAplDatabaseServer"));

        formApplicationDbConfiguration->setWidget(0, QFormLayout::FieldRole, lnAplDatabaseServer);

        lblAplDatabase = new QLabel(tabApplicationDbConfiguration);
        lblAplDatabase->setObjectName(QString::fromUtf8("lblAplDatabase"));

        formApplicationDbConfiguration->setWidget(1, QFormLayout::LabelRole, lblAplDatabase);

        lnAplDatabase = new QLineEdit(tabApplicationDbConfiguration);
        lnAplDatabase->setObjectName(QString::fromUtf8("lnAplDatabase"));

        formApplicationDbConfiguration->setWidget(1, QFormLayout::FieldRole, lnAplDatabase);

        lblAplUserID = new QLabel(tabApplicationDbConfiguration);
        lblAplUserID->setObjectName(QString::fromUtf8("lblAplUserID"));

        formApplicationDbConfiguration->setWidget(2, QFormLayout::LabelRole, lblAplUserID);

        lnAplUserID = new QLineEdit(tabApplicationDbConfiguration);
        lnAplUserID->setObjectName(QString::fromUtf8("lnAplUserID"));

        formApplicationDbConfiguration->setWidget(2, QFormLayout::FieldRole, lnAplUserID);

        lblAplPassword = new QLabel(tabApplicationDbConfiguration);
        lblAplPassword->setObjectName(QString::fromUtf8("lblAplPassword"));

        formApplicationDbConfiguration->setWidget(3, QFormLayout::LabelRole, lblAplPassword);

        lnAplPassword = new QLineEdit(tabApplicationDbConfiguration);
        lnAplPassword->setObjectName(QString::fromUtf8("lnAplPassword"));

        formApplicationDbConfiguration->setWidget(3, QFormLayout::FieldRole, lnAplPassword);


        verticalLayout_2->addLayout(formApplicationDbConfiguration);

        tabApplicationConfiguration->addTab(tabApplicationDbConfiguration, QString());
        tabLoggingConfiguration = new QWidget();
        tabLoggingConfiguration->setObjectName(QString::fromUtf8("tabLoggingConfiguration"));
        verticalLayout_3 = new QVBoxLayout(tabLoggingConfiguration);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        formLoggingConfiguration = new QFormLayout();
        formLoggingConfiguration->setObjectName(QString::fromUtf8("formLoggingConfiguration"));
        lblLogLogging = new QLabel(tabLoggingConfiguration);
        lblLogLogging->setObjectName(QString::fromUtf8("lblLogLogging"));

        formLoggingConfiguration->setWidget(0, QFormLayout::LabelRole, lblLogLogging);

        lnLogLoggingServer = new QLineEdit(tabLoggingConfiguration);
        lnLogLoggingServer->setObjectName(QString::fromUtf8("lnLogLoggingServer"));

        formLoggingConfiguration->setWidget(0, QFormLayout::FieldRole, lnLogLoggingServer);

        lblLogLoggingDatabase = new QLabel(tabLoggingConfiguration);
        lblLogLoggingDatabase->setObjectName(QString::fromUtf8("lblLogLoggingDatabase"));

        formLoggingConfiguration->setWidget(1, QFormLayout::LabelRole, lblLogLoggingDatabase);

        lnLogLoggingDatabase = new QLineEdit(tabLoggingConfiguration);
        lnLogLoggingDatabase->setObjectName(QString::fromUtf8("lnLogLoggingDatabase"));

        formLoggingConfiguration->setWidget(1, QFormLayout::FieldRole, lnLogLoggingDatabase);

        lblLogUserId = new QLabel(tabLoggingConfiguration);
        lblLogUserId->setObjectName(QString::fromUtf8("lblLogUserId"));

        formLoggingConfiguration->setWidget(2, QFormLayout::LabelRole, lblLogUserId);

        lnLogUserId = new QLineEdit(tabLoggingConfiguration);
        lnLogUserId->setObjectName(QString::fromUtf8("lnLogUserId"));

        formLoggingConfiguration->setWidget(2, QFormLayout::FieldRole, lnLogUserId);

        lblLogPassword = new QLabel(tabLoggingConfiguration);
        lblLogPassword->setObjectName(QString::fromUtf8("lblLogPassword"));

        formLoggingConfiguration->setWidget(3, QFormLayout::LabelRole, lblLogPassword);

        lnLogPassword = new QLineEdit(tabLoggingConfiguration);
        lnLogPassword->setObjectName(QString::fromUtf8("lnLogPassword"));

        formLoggingConfiguration->setWidget(3, QFormLayout::FieldRole, lnLogPassword);


        verticalLayout_3->addLayout(formLoggingConfiguration);

        tabApplicationConfiguration->addTab(tabLoggingConfiguration, QString());

        verticalLayout->addWidget(tabApplicationConfiguration);

        btnConfig = new QDialogButtonBox(ApplicationSettingsView);
        btnConfig->setObjectName(QString::fromUtf8("btnConfig"));
        btnConfig->setOrientation(Qt::Horizontal);
        btnConfig->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(btnConfig);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(ApplicationSettingsView);
        QObject::connect(btnConfig, SIGNAL(accepted()), ApplicationSettingsView, SLOT(accept()));
        QObject::connect(btnConfig, SIGNAL(rejected()), ApplicationSettingsView, SLOT(reject()));

        tabApplicationConfiguration->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ApplicationSettingsView);
    } // setupUi

    void retranslateUi(QDialog *ApplicationSettingsView)
    {
        ApplicationSettingsView->setWindowTitle(QCoreApplication::translate("ApplicationSettingsView", "Application configuration", nullptr));
        lblAplDatabaseServer->setText(QCoreApplication::translate("ApplicationSettingsView", "Database server:", nullptr));
        lblAplDatabase->setText(QCoreApplication::translate("ApplicationSettingsView", "Database:", nullptr));
        lblAplUserID->setText(QCoreApplication::translate("ApplicationSettingsView", "UserID:", nullptr));
        lblAplPassword->setText(QCoreApplication::translate("ApplicationSettingsView", "Password", nullptr));
        tabApplicationConfiguration->setTabText(tabApplicationConfiguration->indexOf(tabApplicationDbConfiguration), QCoreApplication::translate("ApplicationSettingsView", "Database configuration", nullptr));
        lblLogLogging->setText(QCoreApplication::translate("ApplicationSettingsView", "Logging Server:", nullptr));
        lblLogLoggingDatabase->setText(QCoreApplication::translate("ApplicationSettingsView", "Logging Database:", nullptr));
        lblLogUserId->setText(QCoreApplication::translate("ApplicationSettingsView", "UserId:", nullptr));
        lblLogPassword->setText(QCoreApplication::translate("ApplicationSettingsView", "Password:", nullptr));
        tabApplicationConfiguration->setTabText(tabApplicationConfiguration->indexOf(tabLoggingConfiguration), QCoreApplication::translate("ApplicationSettingsView", "Logging configuration", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ApplicationSettingsView: public Ui_ApplicationSettingsView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICATIONSETTINGSVIEW_H
