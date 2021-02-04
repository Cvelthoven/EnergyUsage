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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionGas;
    QAction *actionExit;
    QAction *actionElectricity;
    QAction *actionWater;
    QAction *actionConfiguration;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOpen_import;
    QMenu *menuOptions;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1092, 659);
        actionGas = new QAction(MainWindow);
        actionGas->setObjectName(QString::fromUtf8("actionGas"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionElectricity = new QAction(MainWindow);
        actionElectricity->setObjectName(QString::fromUtf8("actionElectricity"));
        actionWater = new QAction(MainWindow);
        actionWater->setObjectName(QString::fromUtf8("actionWater"));
        actionConfiguration = new QAction(MainWindow);
        actionConfiguration->setObjectName(QString::fromUtf8("actionConfiguration"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1092, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuOpen_import = new QMenu(menuFile);
        menuOpen_import->setObjectName(QString::fromUtf8("menuOpen_import"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuFile->addAction(menuOpen_import->menuAction());
        menuFile->addAction(actionExit);
        menuOpen_import->addAction(actionGas);
        menuOpen_import->addAction(actionElectricity);
        menuOpen_import->addAction(actionWater);
        menuOptions->addAction(actionConfiguration);

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
        actionConfiguration->setText(QCoreApplication::translate("MainWindow", "Configuration", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuOpen_import->setTitle(QCoreApplication::translate("MainWindow", "Open import", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
