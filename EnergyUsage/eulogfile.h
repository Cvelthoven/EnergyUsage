//---------------------------------------------------------------------------------------
//
//  Class euLogFile
//
//  This class handles recording of the log messages to the general database when available
//  If no application logging database is available the message are writen to a logfile
//
#ifndef EULOGFILE_H
#define EULOGFILE_H

#include <QObject>
#include <QSqlDatabase>
#include <QString>

#include "euapplicationsettings.h"

class euLogFile
{
public:
    euLogFile(QObject *parent);

private:

};

#endif // EULOGFILE_H
