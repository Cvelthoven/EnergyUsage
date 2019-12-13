//---------------------------------------------------------------------------------------
//
//  Class euDatabase
//
//  This class handles the data interaction with the underlying database
//
#include "eudatabase.h"
#include "euapplicationsettings.h"

#include <QMessageBox>
#include <QSqlDatabase>
#include <QString>
#include <QStringList>

euDatabase::euDatabase()
{

    ApplicationSettings = new euApplicationSettings();
    euRetrieveConfig();
    euConnectDB(&strDatabaseName,&strDatabaseServerName,&strDatabaseUserId,&strDatabasePassword);


}

//---------------------------------------------------------------------------------------
//
//  euConnectDB
//
bool euDatabase::euConnectDB(QString *strDatabaseName, QString *strHostName, QString *strUserId, QString *strPassword)
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
        return false;
    }

    sdbEnergyUsage = QSqlDatabase::addDatabase("QPSQL");
    sdbEnergyUsage.setHostName(*strHostName);
    sdbEnergyUsage.setDatabaseName(*strDatabaseName);
    sdbEnergyUsage.setPort(-1);
    if (!sdbEnergyUsage.open(*strUserId,*strPassword))
    {
        msgBox.setText("Failed to open database");
        msgBox.exec();
        return false;
    }

    return true;
}

bool euDatabase::euRetrieveConfig()
{
    bool
        bOK = true;

    int iStrlen;

    //-----------------------------------------------------------------------------------
    //
    //  Get datbase configuration
    strDatabaseServerName = ApplicationSettings->euGetAppSetting(strDatabaseSection, strKeyDbServerName);
    iStrlen = strDatabaseServerName.length();
    if (iStrlen == 0)
    {
        bOK = ApplicationSettings->euSetAppSetting(strDatabaseSection,strKeyDbServerName,strDatabaseServerNameDef);
        strDatabaseServerName = strDatabaseServerNameDef;
    }
    strDatabaseName = ApplicationSettings->euGetAppSetting(strDatabaseSection, strKeyDbName);
    iStrlen = strDatabaseName.length();
    if (iStrlen == 0)
    {
        bOK = ApplicationSettings->euSetAppSetting(strDatabaseSection,strKeyDbName,strDatabaseNameDef);
        strDatabaseName = strDatabaseNameDef;
    }
    strDatabaseUserId = ApplicationSettings->euGetAppSetting(strDatabaseSection, strKeyDbUserId);
    iStrlen = strDatabaseUserId.length();
    if (iStrlen == 0)
    {
        bOK = ApplicationSettings->euSetAppSetting(strDatabaseSection,strKeyDbUserId,strDatabaseUserIdDef);
        strDatabaseUserId = strDatabaseUserIdDef;
    }
    strDatabasePassword = ApplicationSettings->euGetAppSetting(strDatabaseSection, strKeyDbPassword);
    iStrlen = strDatabasePassword.length();
    if (iStrlen == 0)
    {
        bOK = ApplicationSettings->euSetAppSetting(strDatabaseSection,strKeyDbPassword,strDatabasePasswordDef);
        strDatabasePassword = strDatabasePasswordDef;
    }


    return(bOK);
}
