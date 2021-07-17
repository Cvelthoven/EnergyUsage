//---------------------------------------------------------------------------------------
//
//  class containing the data model functions of energyusage
//
//---------------------------------------------------------------------------------------
#ifndef ENERGYUSAGEDATAMODEL_H
#define ENERGYUSAGEDATAMODEL_H

#include <QObject>
//#include <QAbstractTableModel>
#include <QSqlQueryModel>
#include <QString>

//---------------------------------------------------------------------------------------
//  project include files
#include "applicationlogging.h"

//class EnergyUsageDataModel : public QAbstractTableModel
//{
//    Q_OBJECT
//public:
//    EnergyUsageDataModel(QObject *parent = nullptr);
//    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
//    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
//    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

//};
class EnergyUsageDataModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    EnergyUsageDataModel(QObject *parent, ApplicationLogging *ApplicationLog);

    bool dbConnect = false;// indicator that database connection is available

private:
    bool InitializeDbConnection();
    bool dbConnection();
    bool dbDriveInstalled();
    bool RetrieveDbConfiguration();

//---------------------------------------------------------------------------------------
//  Application logging variables
ApplicationSettingsModel*AppSettings;
ApplicationLogging *dbApplicationLog;

QString
    strDbDriverName = "QPSQL",
    strAppDatabaseServerName,
    strAplDatabaseName,
    strAplDatabaseUserId,
    strAplDatabasePassword,
    strLogMessage,
    strSeverity;

QSqlDatabase
    sdbApplicationdb;


};

#endif // ENERGYUSAGEDATAMODEL_H
