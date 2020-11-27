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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
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
    QWidget *centralWidget;
    QTableView *tbvDatabaseView;
    QLineEdit *TestLineEdit;
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
        tbvDatabaseView = new QTableView(centralWidget);
        tbvDatabaseView->setObjectName(QString::fromUtf8("tbvDatabaseView"));
        tbvDatabaseView->setGeometry(QRect(110, 100, 601, 311));
        TestLineEdit = new QLineEdit(centralWidget);
        TestLineEdit->setObjectName(QString::fromUtf8("TestLineEdit"));
        TestLineEdit->setGeometry(QRect(130, 20, 113, 25));
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
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuOpen_import->setTitle(QCoreApplication::translate("MainWindow", "Open import", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
