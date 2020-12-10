/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionGas;
    QAction *actionExit;
    QAction *actionElectricity;
    QAction *actionWater;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *DatabaseLoggingLayout;
    QFormLayout *DatabaseForm;
    QLabel *applicationServerLabel;
    QLineEdit *applicationServerLineEdit;
    QLabel *applicationDatabaseLabel;
    QLineEdit *applicationDatabaseLineEdit;
    QLabel *useridLabel;
    QLineEdit *useridLineEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QFormLayout *LoggingForm;
    QLineEdit *loggingServerLineEdit;
    QLabel *loggingServerLabel;
    QLabel *loggingDatabaseLabel;
    QLineEdit *loggingDatabaseLineEdit;
    QLabel *useridLabel_2;
    QLineEdit *useridLineEdit_2;
    QLabel *passwordLabel_2;
    QLineEdit *passwordLineEdit_2;
    QHBoxLayout *buttonslayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnStart;
    QPushButton *btnExit;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOpen_import;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(908, 521);
        actionGas = new QAction(MainWindow);
        actionGas->setObjectName(QString::fromUtf8("actionGas"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionElectricity = new QAction(MainWindow);
        actionElectricity->setObjectName(QString::fromUtf8("actionElectricity"));
        actionWater = new QAction(MainWindow);
        actionWater->setObjectName(QString::fromUtf8("actionWater"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        DatabaseLoggingLayout = new QHBoxLayout();
        DatabaseLoggingLayout->setSpacing(6);
        DatabaseLoggingLayout->setObjectName(QString::fromUtf8("DatabaseLoggingLayout"));
        DatabaseForm = new QFormLayout();
        DatabaseForm->setSpacing(6);
        DatabaseForm->setObjectName(QString::fromUtf8("DatabaseForm"));
        applicationServerLabel = new QLabel(centralWidget);
        applicationServerLabel->setObjectName(QString::fromUtf8("applicationServerLabel"));

        DatabaseForm->setWidget(0, QFormLayout::LabelRole, applicationServerLabel);

        applicationServerLineEdit = new QLineEdit(centralWidget);
        applicationServerLineEdit->setObjectName(QString::fromUtf8("applicationServerLineEdit"));

        DatabaseForm->setWidget(0, QFormLayout::FieldRole, applicationServerLineEdit);

        applicationDatabaseLabel = new QLabel(centralWidget);
        applicationDatabaseLabel->setObjectName(QString::fromUtf8("applicationDatabaseLabel"));

        DatabaseForm->setWidget(1, QFormLayout::LabelRole, applicationDatabaseLabel);

        applicationDatabaseLineEdit = new QLineEdit(centralWidget);
        applicationDatabaseLineEdit->setObjectName(QString::fromUtf8("applicationDatabaseLineEdit"));

        DatabaseForm->setWidget(1, QFormLayout::FieldRole, applicationDatabaseLineEdit);

        useridLabel = new QLabel(centralWidget);
        useridLabel->setObjectName(QString::fromUtf8("useridLabel"));

        DatabaseForm->setWidget(2, QFormLayout::LabelRole, useridLabel);

        useridLineEdit = new QLineEdit(centralWidget);
        useridLineEdit->setObjectName(QString::fromUtf8("useridLineEdit"));

        DatabaseForm->setWidget(2, QFormLayout::FieldRole, useridLineEdit);

        passwordLabel = new QLabel(centralWidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        DatabaseForm->setWidget(3, QFormLayout::LabelRole, passwordLabel);

        passwordLineEdit = new QLineEdit(centralWidget);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));

        DatabaseForm->setWidget(3, QFormLayout::FieldRole, passwordLineEdit);


        DatabaseLoggingLayout->addLayout(DatabaseForm);

        LoggingForm = new QFormLayout();
        LoggingForm->setSpacing(6);
        LoggingForm->setObjectName(QString::fromUtf8("LoggingForm"));
        loggingServerLineEdit = new QLineEdit(centralWidget);
        loggingServerLineEdit->setObjectName(QString::fromUtf8("loggingServerLineEdit"));

        LoggingForm->setWidget(0, QFormLayout::FieldRole, loggingServerLineEdit);

        loggingServerLabel = new QLabel(centralWidget);
        loggingServerLabel->setObjectName(QString::fromUtf8("loggingServerLabel"));

        LoggingForm->setWidget(0, QFormLayout::LabelRole, loggingServerLabel);

        loggingDatabaseLabel = new QLabel(centralWidget);
        loggingDatabaseLabel->setObjectName(QString::fromUtf8("loggingDatabaseLabel"));

        LoggingForm->setWidget(1, QFormLayout::LabelRole, loggingDatabaseLabel);

        loggingDatabaseLineEdit = new QLineEdit(centralWidget);
        loggingDatabaseLineEdit->setObjectName(QString::fromUtf8("loggingDatabaseLineEdit"));

        LoggingForm->setWidget(1, QFormLayout::FieldRole, loggingDatabaseLineEdit);

        useridLabel_2 = new QLabel(centralWidget);
        useridLabel_2->setObjectName(QString::fromUtf8("useridLabel_2"));

        LoggingForm->setWidget(2, QFormLayout::LabelRole, useridLabel_2);

        useridLineEdit_2 = new QLineEdit(centralWidget);
        useridLineEdit_2->setObjectName(QString::fromUtf8("useridLineEdit_2"));

        LoggingForm->setWidget(2, QFormLayout::FieldRole, useridLineEdit_2);

        passwordLabel_2 = new QLabel(centralWidget);
        passwordLabel_2->setObjectName(QString::fromUtf8("passwordLabel_2"));

        LoggingForm->setWidget(3, QFormLayout::LabelRole, passwordLabel_2);

        passwordLineEdit_2 = new QLineEdit(centralWidget);
        passwordLineEdit_2->setObjectName(QString::fromUtf8("passwordLineEdit_2"));

        LoggingForm->setWidget(3, QFormLayout::FieldRole, passwordLineEdit_2);


        DatabaseLoggingLayout->addLayout(LoggingForm);


        verticalLayout->addLayout(DatabaseLoggingLayout);

        buttonslayout = new QHBoxLayout();
        buttonslayout->setSpacing(6);
        buttonslayout->setObjectName(QString::fromUtf8("buttonslayout"));
        horizontalSpacer = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonslayout->addItem(horizontalSpacer);

        btnStart = new QPushButton(centralWidget);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));
        btnStart->setMinimumSize(QSize(100, 30));

        buttonslayout->addWidget(btnStart);

        btnExit = new QPushButton(centralWidget);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setMinimumSize(QSize(100, 30));

        buttonslayout->addWidget(btnExit);

        horizontalSpacer_2 = new QSpacerItem(238, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonslayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(buttonslayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 908, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuOpen_import = new QMenu(menuFile);
        menuOpen_import->setObjectName(QString::fromUtf8("menuOpen_import"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(menuOpen_import->menuAction());
        menuFile->addAction(actionExit);
        menuOpen_import->addAction(actionGas);
        menuOpen_import->addAction(actionElectricity);
        menuOpen_import->addAction(actionWater);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionGas->setText(QCoreApplication::translate("MainWindow", "Gas", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionElectricity->setText(QCoreApplication::translate("MainWindow", "Electricity", nullptr));
        actionWater->setText(QCoreApplication::translate("MainWindow", "Water", nullptr));
        applicationServerLabel->setText(QCoreApplication::translate("MainWindow", "Application server:", nullptr));
        applicationDatabaseLabel->setText(QCoreApplication::translate("MainWindow", "Application database:", nullptr));
        useridLabel->setText(QCoreApplication::translate("MainWindow", "Userid:", nullptr));
        passwordLabel->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        loggingServerLabel->setText(QCoreApplication::translate("MainWindow", "Logging server:", nullptr));
        loggingDatabaseLabel->setText(QCoreApplication::translate("MainWindow", "Logging database:", nullptr));
        useridLabel_2->setText(QCoreApplication::translate("MainWindow", "Userid:", nullptr));
        passwordLabel_2->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        btnStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        btnExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuOpen_import->setTitle(QCoreApplication::translate("MainWindow", "Open import", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
