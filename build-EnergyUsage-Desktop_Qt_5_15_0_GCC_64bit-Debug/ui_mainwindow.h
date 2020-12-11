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
#include <QtWidgets/QStackedWidget>
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
    QStackedWidget *stackedWidget;
    QWidget *StartUpPage;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *DatabaseLoggingLayout;
    QFormLayout *DatabaseForm;
    QLabel *applicationServerLabel;
    QLineEdit *applicationServerLineEdit;
    QLabel *applicationDatabaseLabel;
    QLineEdit *applicationDatabaseLineEdit;
    QLabel *applicationDatabaseUseridLabel;
    QLineEdit *applicationDatabaseUseridLineEdit;
    QLabel *applicationDatabasePasswordLabel;
    QLineEdit *applicationDatabasePasswordLineEdit;
    QFormLayout *LoggingForm;
    QLineEdit *loggingServerLineEdit;
    QLabel *loggingServerLabel;
    QLabel *loggingDatabaseLabel;
    QLineEdit *loggingDatabaseLineEdit;
    QLabel *loggingUseridLabel;
    QLineEdit *loggingUseridLineEdit;
    QLabel *loggingPasswordLabel;
    QLineEdit *loggingPasswordLineEdit;
    QHBoxLayout *buttonslayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnStart;
    QPushButton *btnExit;
    QSpacerItem *horizontalSpacer_2;
    QWidget *page_2;
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
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        StartUpPage = new QWidget();
        StartUpPage->setObjectName(QString::fromUtf8("StartUpPage"));
        verticalLayout_2 = new QVBoxLayout(StartUpPage);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        DatabaseLoggingLayout = new QHBoxLayout();
        DatabaseLoggingLayout->setSpacing(6);
        DatabaseLoggingLayout->setObjectName(QString::fromUtf8("DatabaseLoggingLayout"));
        DatabaseForm = new QFormLayout();
        DatabaseForm->setSpacing(6);
        DatabaseForm->setObjectName(QString::fromUtf8("DatabaseForm"));
        applicationServerLabel = new QLabel(StartUpPage);
        applicationServerLabel->setObjectName(QString::fromUtf8("applicationServerLabel"));

        DatabaseForm->setWidget(0, QFormLayout::LabelRole, applicationServerLabel);

        applicationServerLineEdit = new QLineEdit(StartUpPage);
        applicationServerLineEdit->setObjectName(QString::fromUtf8("applicationServerLineEdit"));

        DatabaseForm->setWidget(0, QFormLayout::FieldRole, applicationServerLineEdit);

        applicationDatabaseLabel = new QLabel(StartUpPage);
        applicationDatabaseLabel->setObjectName(QString::fromUtf8("applicationDatabaseLabel"));

        DatabaseForm->setWidget(1, QFormLayout::LabelRole, applicationDatabaseLabel);

        applicationDatabaseLineEdit = new QLineEdit(StartUpPage);
        applicationDatabaseLineEdit->setObjectName(QString::fromUtf8("applicationDatabaseLineEdit"));

        DatabaseForm->setWidget(1, QFormLayout::FieldRole, applicationDatabaseLineEdit);

        applicationDatabaseUseridLabel = new QLabel(StartUpPage);
        applicationDatabaseUseridLabel->setObjectName(QString::fromUtf8("applicationDatabaseUseridLabel"));

        DatabaseForm->setWidget(2, QFormLayout::LabelRole, applicationDatabaseUseridLabel);

        applicationDatabaseUseridLineEdit = new QLineEdit(StartUpPage);
        applicationDatabaseUseridLineEdit->setObjectName(QString::fromUtf8("applicationDatabaseUseridLineEdit"));

        DatabaseForm->setWidget(2, QFormLayout::FieldRole, applicationDatabaseUseridLineEdit);

        applicationDatabasePasswordLabel = new QLabel(StartUpPage);
        applicationDatabasePasswordLabel->setObjectName(QString::fromUtf8("applicationDatabasePasswordLabel"));

        DatabaseForm->setWidget(3, QFormLayout::LabelRole, applicationDatabasePasswordLabel);

        applicationDatabasePasswordLineEdit = new QLineEdit(StartUpPage);
        applicationDatabasePasswordLineEdit->setObjectName(QString::fromUtf8("applicationDatabasePasswordLineEdit"));
        applicationDatabasePasswordLineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        DatabaseForm->setWidget(3, QFormLayout::FieldRole, applicationDatabasePasswordLineEdit);


        DatabaseLoggingLayout->addLayout(DatabaseForm);

        LoggingForm = new QFormLayout();
        LoggingForm->setSpacing(6);
        LoggingForm->setObjectName(QString::fromUtf8("LoggingForm"));
        loggingServerLineEdit = new QLineEdit(StartUpPage);
        loggingServerLineEdit->setObjectName(QString::fromUtf8("loggingServerLineEdit"));

        LoggingForm->setWidget(0, QFormLayout::FieldRole, loggingServerLineEdit);

        loggingServerLabel = new QLabel(StartUpPage);
        loggingServerLabel->setObjectName(QString::fromUtf8("loggingServerLabel"));

        LoggingForm->setWidget(0, QFormLayout::LabelRole, loggingServerLabel);

        loggingDatabaseLabel = new QLabel(StartUpPage);
        loggingDatabaseLabel->setObjectName(QString::fromUtf8("loggingDatabaseLabel"));

        LoggingForm->setWidget(1, QFormLayout::LabelRole, loggingDatabaseLabel);

        loggingDatabaseLineEdit = new QLineEdit(StartUpPage);
        loggingDatabaseLineEdit->setObjectName(QString::fromUtf8("loggingDatabaseLineEdit"));

        LoggingForm->setWidget(1, QFormLayout::FieldRole, loggingDatabaseLineEdit);

        loggingUseridLabel = new QLabel(StartUpPage);
        loggingUseridLabel->setObjectName(QString::fromUtf8("loggingUseridLabel"));

        LoggingForm->setWidget(2, QFormLayout::LabelRole, loggingUseridLabel);

        loggingUseridLineEdit = new QLineEdit(StartUpPage);
        loggingUseridLineEdit->setObjectName(QString::fromUtf8("loggingUseridLineEdit"));

        LoggingForm->setWidget(2, QFormLayout::FieldRole, loggingUseridLineEdit);

        loggingPasswordLabel = new QLabel(StartUpPage);
        loggingPasswordLabel->setObjectName(QString::fromUtf8("loggingPasswordLabel"));

        LoggingForm->setWidget(3, QFormLayout::LabelRole, loggingPasswordLabel);

        loggingPasswordLineEdit = new QLineEdit(StartUpPage);
        loggingPasswordLineEdit->setObjectName(QString::fromUtf8("loggingPasswordLineEdit"));
        loggingPasswordLineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        LoggingForm->setWidget(3, QFormLayout::FieldRole, loggingPasswordLineEdit);


        DatabaseLoggingLayout->addLayout(LoggingForm);


        verticalLayout_2->addLayout(DatabaseLoggingLayout);

        buttonslayout = new QHBoxLayout();
        buttonslayout->setSpacing(6);
        buttonslayout->setObjectName(QString::fromUtf8("buttonslayout"));
        horizontalSpacer = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonslayout->addItem(horizontalSpacer);

        btnStart = new QPushButton(StartUpPage);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));
        btnStart->setMinimumSize(QSize(100, 30));

        buttonslayout->addWidget(btnStart);

        btnExit = new QPushButton(StartUpPage);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setMinimumSize(QSize(100, 30));

        buttonslayout->addWidget(btnExit);

        horizontalSpacer_2 = new QSpacerItem(238, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonslayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(buttonslayout);

        stackedWidget->addWidget(StartUpPage);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);

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

        stackedWidget->setCurrentIndex(0);


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
        applicationDatabaseUseridLabel->setText(QCoreApplication::translate("MainWindow", "Userid:", nullptr));
        applicationDatabasePasswordLabel->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        loggingServerLabel->setText(QCoreApplication::translate("MainWindow", "Logging server:", nullptr));
        loggingDatabaseLabel->setText(QCoreApplication::translate("MainWindow", "Logging database:", nullptr));
        loggingUseridLabel->setText(QCoreApplication::translate("MainWindow", "Userid:", nullptr));
        loggingPasswordLabel->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
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
