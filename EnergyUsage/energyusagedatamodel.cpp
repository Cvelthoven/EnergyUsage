//---------------------------------------------------------------------------------------
//
//  class containing the data model functions of energyusage
//
//---------------------------------------------------------------------------------------
#include "energyusage.h"
#include "energyusagedatamodel.h"

//#include <QAbstractTableModel>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QStringList>

//EnergyUsageDataModel::EnergyUsageDataModel(QObject *parent)
//        : QAbstractTableModel(parent)
//{

//}

//---------------------------------------------------------------------------------------
//--------- Copy mymodel tutorial
//int EnergyUsageDataModel::rowCount(const QModelIndex & /*parent*/) const
//{
//   return 2;
//}

//int EnergyUsageDataModel::columnCount(const QModelIndex & /*parent*/) const
//{
//    return 3;
//}

//QVariant EnergyUsageDataModel::data(const QModelIndex &index, int role) const
//{
//    if (role == Qt::DisplayRole)
//       return QString("Row%1, Column%2")
//                   .arg(index.row() + 1)
//                   .arg(index.column() +1);
//
//    return QVariant();
//}

//---------------------------------------------------------------------------------------
//  Trial with QSqlQueryModel
EnergyUsageDataModel::EnergyUsageDataModel(QObject *parent, ApplicationLogging *ApplicationLog)
        : QSqlQueryModel(parent)
{
    AppSettings = new ApplicationSettingsModel();
    dbApplicationLog = ApplicationLog;

    //-----------------------------------------------------------------------------------
    //
    //  Retrieve database settings from the application configuration
    //
    RetrieveDbConfiguration();

    //-----------------------------------------------------------------------------------
    //
    //  Initialze database connection
    //
    if (!InitializeDbConnection())
    {
        strSeverity = "Error";
        strLogMessage = "No database connection available";
        dbApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
        dbConnect = false;

    }

    QSqlQueryModel DataModel;
    DataModel.setQuery("SELECT * FROM eu_gas_usage");

}

//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//
//  Create the database connection to the application database
//
bool EnergyUsageDataModel::InitializeDbConnection()
{
    if (!dbDriveInstalled())
        return false;
    if (!dbConnection())
        return false;

    return true;
}

//---------------------------------------------------------------------------------------
//
//  Database driver check
//
bool EnergyUsageDataModel::dbDriveInstalled()
{
    QStringList
            stlDbDrivers;

    //-----------------------------------------------------------------------------------
    //
    //  Verify that the database type driver is available
    //-----------------------------------------------------------------------------------
    //
    //  Load Postgresql driver
    //
    stlDbDrivers = QSqlDatabase::drivers();
    if (!stlDbDrivers.contains(strDbDriverName))
    {
        strSeverity = "Error";
        strLogMessage = "No " + strDbDriverName + " driver found";
        dbApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
        return false;
    }

    strSeverity = "Info";
    strLogMessage = strDbDriverName + " driver found";
    dbApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
    return true;
}

//---------------------------------------------------------------------------------------
//
//  Connect application database
//
bool EnergyUsageDataModel::dbConnection()
{
    //-----------------------------------------------------------------------------------
    //
    //  Open database
    //
    sdbApplicationdb = QSqlDatabase::addDatabase(strDbDriverName,"EnergyUsage");
    sdbApplicationdb.setHostName(strAppDatabaseServerName);
    sdbApplicationdb.setDatabaseName(strAplDatabaseName);
    sdbApplicationdb.setPort(-1);
    if (!sdbApplicationdb.open(strAplDatabaseUserId,strAplDatabasePassword))
    {
        strSeverity = "Error";
        strLogMessage = "Unable to connect to database: " + strAplDatabaseName;
        dbApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
        return false;
    }
    else
    {
        strSeverity = "Info";
        strLogMessage = "Connected to database: " + strAplDatabaseName;
        dbApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
    }

    return true;
}

//---------------------------------------------------------------------------------------
//
//  Retrieve the application database configuration from the settings
//
bool EnergyUsageDataModel::RetrieveDbConfiguration()
{
    bool
        bOK = true;
    int
        iStrlen;

    strSeverity = "Error";
    //  Get database servername
    strAppDatabaseServerName = AppSettings->GetAppSetting(strDatabaseSection, strKeyDbServerName);
    iStrlen = strAppDatabaseServerName.length();
    if (iStrlen == 0)
    {
        strLogMessage = strKeyDbServerName + "Database server not set.";
        dbApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
        bOK = false;
    }
    //
    //  Get database name
    strAplDatabaseName = AppSettings->GetAppSetting(strDatabaseSection, strKeyDbName);
    iStrlen = strAplDatabaseName.length();
    if (iStrlen == 0)
    {
        strLogMessage = strKeyDbName + "Database name not set";
        dbApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
        bOK = false;
    }
    //
    //  Get database Username
    strAplDatabaseUserId = AppSettings->GetAppSetting(strDatabaseSection, strKeyDbUserId);
    iStrlen = strAplDatabaseUserId.length();
    if (iStrlen == 0)
    {
        strLogMessage = strKeyDbUserId + "Application database userid not set.";
        dbApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
        bOK = false;
    }
    //
    //  Get database Password
    strAplDatabasePassword = AppSettings->GetAppSetting(strDatabaseSection, strKeyDbPassword);
    iStrlen = strAplDatabasePassword.length();
    if (iStrlen == 0)
    {
        strLogMessage = strKeyDbPassword + "Application database password not set.";
        dbApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
        bOK = false;
    }
    return(bOK);

}
