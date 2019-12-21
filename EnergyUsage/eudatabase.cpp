//---------------------------------------------------------------------------------------
//
//  Class euDatabase
//
//  This class handles the data interaction with the underlying database
//
#include "eudatabase.h"
#include "euapplicationsettings.h"
#include "eulogfile.h"

#include <QMessageBox>
#include <QSqlDatabase>
#include <QtSql>
#include <QString>
#include <QStringList>

#include <QDebug>

//---------------------------------------------------------------------------------------
//
//  Constructor
//
euDatabase::euDatabase(QObject *parent)
    : QStandardItemModel(parent)
{

    ApplicationSettings = new euApplicationSettings();
    euRetrieveConfig();
    euConnectDB(&strDatabaseName,&strDatabaseServerName,&strDatabaseUserId,&strDatabasePassword);


}

//---------------------------------------------------------------------------------------
//
//  euConnectDB
//
//  Connects to the database and verifies that the tables exist or let them be created
//
bool euDatabase::euConnectDB(QString *strDatabaseName, QString *strHostName, QString *strUserId, QString *strPassword)
{
    QStringList
            stlDbDrivers;

    QMessageBox
        msgBox;

    //-----------------------------------------------------------------------------------
    //
    //  Load Postgresql driver
    //
    stlDbDrivers = QSqlDatabase::drivers();
    if (!stlDbDrivers.contains("QPSQL"))
    {
        msgBox.setText("Postgress SQL driver not found");
        msgBox.exec();
        return false;
    }

    //-----------------------------------------------------------------------------------
    //
    //  Open database
    //
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

    //-----------------------------------------------------------------------------------
    //
    //  Check tables
    //
    stlDbTables = sdbEnergyUsage.tables();
    //
    //  Check application_log table exists
    if (!stlDbTables.contains(strTblNameApplicationLog))
    {
        if (!euLogCreateTable())
        {
            return false;
        }
    }
    //
    //  Check eu_gas_usage table exists
    if (!stlDbTables.contains(strTblGasName))
    {
        if (!euGasCreateTable())
        {
            return false;
        }
    }

    return true;
}

//---------------------------------------------------------------------------------------
//
//  euGasCreateTable
//
//  Creates the table: strTblGasName
//
bool euDatabase::euGasCreateTable()
{
QString
    strQuery;

    //-----------------------------------------------------------------------------------
    //
    //  Build build query of strTblGasName
    strQuery = "CREATE TABLE " + strTblGasName + " (";
    strQuery.append(strFldGasRecId + " SERIAL PRIMARY KEY, ");
    strQuery.append(strFldDateStart + " date, ");
    strQuery.append(strFldTimeStart + " time without time zone, ");
    strQuery.append(strFldDateEnd + " date, ");
    strQuery.append(strFldTimeEnd + " time without time zone, ");
    strQuery.append(strFldActualUsage + " numeric(10,4), ");
    strQuery.append(strFldExpectedUsage + " numeric(10,4), ");
    strQuery.append(strFldResult + " integer, ");
    strQuery.append(strFldDegreeDay + " numeric(8,4), ");
    strQuery.append(strFldPerDegreeDay + " numeric(8,4)");
    strQuery.append(");");


    //-----------------------------------------------------------------------------------
    //
    //  Create eu_gas_usage table
    //
    QSqlQuery qQuery("",sdbEnergyUsage);
    if (!qQuery.exec(strQuery))
    {
        qDebug() << sdbEnergyUsage.lastError();
        return false;
    }

    return true;
}

//---------------------------------------------------------------------------------------
//
//  euLogCreateTable
//
//  Creates the table: application_log
//
bool euDatabase::euLogCreateTable()
{
QString
    strQuery;

    //-----------------------------------------------------------------------------------
    //
    //  Build build query of strTblGasName
    strQuery = "CREATE TABLE " + strTblNameApplicationLog + " (";
    strQuery.append(strFldAplRecId + " SERIAL PRIMARY KEY, ");
    strQuery.append(strFldAplApplicationName + " \"char\" NOT NULL, ");
//    strQuery.append(" \"char\" NOT NULL, ");
    strQuery.append(strFldAplTimeStamp + " timestamp without time zone NOT NULL, ");
    strQuery.append(strFldAplLogMessage + " \"char\" NOT NULL");
//    strQuery.append(" \"char\" NOT NULL");
    strQuery.append(");");

    //-----------------------------------------------------------------------------------
    //
    //  Create eu_gas_usage table
    //
    QSqlQuery qQuery("",sdbEnergyUsage);
    if (!qQuery.exec(strQuery))
    {
        qDebug() << sdbEnergyUsage.lastError();
        return false;
    }

    return true;
}


//---------------------------------------------------------------------------------------
//
//  euRetrieveConfig
//
//  Retrieves the database related application settings
//
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
