//---------------------------------------------------------------------------------------
//
//  Class euDatabase
//
//  This class handles the data interaction with the underlying database
//
#include "eudatabase.h"

#include <QMessageBox>
#include <QSqlDatabase>
#include <QString>
#include <QStringList>

euDatabase::euDatabase()
{

}

//---------------------------------------------------------------------------------------
//
//  euConnectDB
//
void euConnectDB(QString *strDatabaseName, QString *strHostName, QString *strUserId, QString *strPassword)
{
    QStringList
            stlDbDrivers;

    QSqlDatabase
        sdbEnergyUsage;

    QMessageBox
        msgBox;


        //-----------------------------------------------------------------------------------
        //
        //  Connect to database
        //
        stlDbDrivers = QSqlDatabase::drivers();
        if (!stlDbDrivers.contains("QPSQL"))
        {
            msgBox.setText("Postgress SQL driver not found");
            msgBox.exec();
            exit(0);
        }

        sdbEnergyUsage = QSqlDatabase::addDatabase("QPSQL");
        sdbEnergyUsage.setHostName(*strHostName);
        sdbEnergyUsage.setDatabaseName(*strDatabaseName);
        sdbEnergyUsage.setPort(-1);
        if (!sdbEnergyUsage.open(*strUserId,*strPassword))
        {
            msgBox.setText("Failed to open database");
            msgBox.exec();
            exit(0);
        }

}
