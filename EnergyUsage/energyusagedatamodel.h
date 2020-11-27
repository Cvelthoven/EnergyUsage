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
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

};

#endif // ENERGYUSAGEDATAMODEL_H
