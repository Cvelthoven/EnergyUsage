//---------------------------------------------------------------------------------------
//
//  Class ImportMetricsFile
//
//  This class handles the import from metrics to the database
//
#ifndef IMPORTMETRICSFILE_H
#define IMPORTMETRICSFILE_H

#include <QMainWindow>
#include <QObject>
#include <QString>
#include <QWidget>

class ImportMetricsFile
{
public:
    ImportMetricsFile();
    ImportMetricsFile(QString *strMetricType, QString *strImportFileName);
};

#endif // IMPORTMETRICSFILE_H
