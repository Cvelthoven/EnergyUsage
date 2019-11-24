#ifndef EUDATABASE_H
#define EUDATABASE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include <QMessageBox>
#include <QSqlDatabase>
#include <QString>
#include <QStringList>

class euDatabase
{

public:
    euDatabase();
    void euConnectDB(QString *strDatabaseName, QString *strHostName, QString *strUserId, QString *strPassword);

private:
//    QSqlDatabase
//        sdbEnergyUsage;

//    QMessageBox
//        msgBox;

};

#endif // EUDATABASE_H
