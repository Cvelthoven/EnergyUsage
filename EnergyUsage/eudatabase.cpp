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

//    QSqlDatabase
//        sdbEnergyUsage;

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
    strQuery.append(strFldGasRecId + " integer NOT NULL, ");
    strQuery.append(strFldDateStart + " date, ");
    strQuery.append(strFldTimeStart + " time without time zone,");
    strQuery.append(strFldDateEnd + "date,");
    strQuery.append(strFldTimeEnd + " time without time zone,");
    strQuery.append(strFldActualUsage + " numeric(10,4),");
    strQuery.append(strFldExpectedUsage + " numeric(10,4),");
    strQuery.append(strFldResult + " integer,");
    strQuery.append(strFldDegreeDay + " numeric(8,4),");
    strQuery.append(strFldPerDegreeDay + " numeric(8,4),");
    strQuery.append("CONSTRAINT ");
    strQuery.append('"');
    strQuery.append("euGasUsage_pkey");
    strQuery.append('"');
    strQuery.append(" PRIMARY KEY (");
    strQuery.append('"');
    strQuery.append(strFldGasRecId);
    strQuery.append('"');
    strQuery.append(");");

//            strTblGasName       = "euGasUsage",
//            strFldGasRecId      = "euGasRecId",
//            strFldDateStart     = "euGasDateStart",
//            strFldTimeStart     = "euGasTimeStart",
//            strFldDateEnd       = "euGasDateEnd",
//            strFldTimeEnd       = "euGasTimeEnd",
//            strFldActualUsage   = "euGasActualUsage",
//            strFldExpectedUsage = "euGasExpectedUsage",
//            strFldResult        = "euGasResult",
//            strFldDegreeDay     = "euGasDegreeDay",
//            strFldPerDegreeDay  = "euGasPerDegreeDay";

//------------------------------------------------------
// Postgres table creation query
//    -- Table: public."euGasUsage"

//    -- DROP TABLE public."euGasUsage";

//    CREATE TABLE public."euGasUsage"
//    (
//      "euGasRecId" integer NOT NULL,
//      "euGasDateStart" date,
//      "euGasTimeStart" time without time zone,
//      "euGasDateEnd" date,
//      "euGasTimeEnd" time without time zone,
//      "euGasActualUsage" numeric(10,4),
//      "euGasExpectedUsage" numeric(10,4),
//      "euGasResult" integer,
//      "euGasDegreeDay" numeric(8,4),
//      "euGasPerDegreeDay" numeric(8,4),
//      CONSTRAINT "euGasUsage_pkey" PRIMARY KEY ("euGasRecId")
//    )
//    WITH (
//      OIDS=FALSE
//    );
//    ALTER TABLE public."euGasUsage"
//      OWNER TO pi;
//--------------------------------------------------------


    return false;
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
