//---------------------------------------------------------------------------------------
//
//  class containing the data model functions of energyusage
//
//---------------------------------------------------------------------------------------
#include "energyusagedatamodel.h"

#include <QAbstractTableModel>

EnergyUsageDataModel::EnergyUsageDataModel(QObject *parent)
        : QAbstractTableModel(parent)
{

}

//---------------------------------------------------------------------------------------
//--------- Copy mymodel tutorial
int EnergyUsageDataModel::rowCount(const QModelIndex & /*parent*/) const
{
   return 2;
}

int EnergyUsageDataModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 3;
}

QVariant EnergyUsageDataModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
       return QString("Row%1, Column%2")
                   .arg(index.row() + 1)
                   .arg(index.column() +1);

    return QVariant();
}
