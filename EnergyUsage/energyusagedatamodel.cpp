//---------------------------------------------------------------------------------------
//
//  class containing the data model functions of energyusage
//
//---------------------------------------------------------------------------------------
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
        strLogMessage = "No Postgresql driver found";
        dbApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
        return false;
    }

    strSeverity = "Info";
    strLogMessage = "Postgresql driver found";
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
//    sdbApplicationdb = QSqlDatabase::addDatabase(strDbDriverName,"EnergyUsage");
//    sdbEnergyUsage.setHostName(*strHostName);
//    sdbEnergyUsage.setDatabaseName(*strDatabaseName);
//    sdbEnergyUsage.setPort(-1);
//    if (!sdbEnergyUsage.open(*strUserId,*strPassword))
//    {
//        strSeverity = "Error";
//        strLogMessage = "Unable to connect to database: " + *strDatabaseName;
//        dbApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
//        return false;
//    }
//    else
//    {
//        strSeverity = "Info";
//        strLogMessage = "Connected to database: " + *strDatabaseName;
//        dbApplicationLog->WriteLogRecord(&strSeverity,&strLogMessage);
//    }


    return true;
}
