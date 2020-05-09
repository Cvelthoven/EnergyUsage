//---------------------------------------------------------------------------------------
//
//  class containing the data model functions of energyusage
//
//---------------------------------------------------------------------------------------
#ifndef ENERGYUSAGEDATAMODEL_H
#define ENERGYUSAGEDATAMODEL_H

#include <QObject>
#include <QAbstractTableModel>

class EnergyUsageDataModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    EnergyUsageDataModel(QObject *parent = nullptr);
};

#endif // ENERGYUSAGEDATAMODEL_H
