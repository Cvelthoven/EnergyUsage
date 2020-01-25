//---------------------------------------------------------------------------------------
//
//  Class ImportMetricsFile
//
//  This class handles the import from metrics to the database
//
#include "importmetricsfile.h"

#include <QFile>
#include <QString>
#include <QTextStream>

//---------------------------------------------------------------------------------------
//
//  Default contructor
//
ImportMetricsFile::ImportMetricsFile()
{

}
//---------------------------------------------------------------------------------------
//
//  Contructor with metric type and filename
//
ImportMetricsFile::ImportMetricsFile(QString *strMetricFileType, QString *strImportFileName)
{
    int iTotalLines = 0,
        iTotalRecords = 0;

    QString
        strInputLine;

    strMetricType = *strMetricFileType;

    //-----------------------------------------------------------------------------------
    //
    //  Open imput file
    //
    QFile qfiImportFile(*strImportFileName);
    if (qfiImportFile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        //-------------------------------------------------------------------------------
        //
        //  Process file line by line
        //
        QTextStream qtsImportFile(&qfiImportFile);
        while (!qtsImportFile.atEnd())
        {
            strInputLine = qtsImportFile.readLine();
            iTotalLines++;
        }
    }
}
