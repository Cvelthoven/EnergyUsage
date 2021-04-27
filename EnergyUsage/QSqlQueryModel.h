//---------------------------------------------------------------------------------------
//
//  euapplicationlogging
//
//  This class handles all application logging to a database or file
//
#ifndef EUAPPLICATIONLOGGING_H
#define EUAPPLICATIONLOGGING_H

#include <QDateTime>
#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include <QSqlDatabase>
#include <QStandardItemModel>
#include <QString>

#include "applicationsettingsmodel.h"

class ApplicationLogging : public QStandardItemModel
{
    Q_OBJECT

public:
    ApplicationLogging(QObject *parent);
    ~ApplicationLogging();
    void WriteLogRecord(const QString *strLogSeverity, const QString *strLogMessage);
    void WriteLogRecord(const QDateTime *qdRecTimeStamp, const QString *strLogSeverity, const QString *strLogMessage);
    void WriteLogRecord(const QString *strAppName, const QDateTime *qdRecTimeStamp, const QString *strLogSeverity, const QString *strLogMessage);

    bool
        bDBconnected;

private:
    bool ConnectDB(QString *strDatabaseName, QString *strHostName, QString *strUserId, QString *strPassword);
    bool LogCreateTable();
    bool RetrieveLogConfig();
    void SendWarningMessage(const QString &strMsgPart1, const QString &strMsgPart2);

    ApplicationSettingsModel *AplLogingSettings;

    QSqlDatabase sdbAppLogDB;

    QString
        strAppLogLoggingType,       // Application loggging type
        strAppLogDatabaseServerName,// Application Logging database server name
        strAppLogDatabaseName,      // Database name
        strAppLogDatabaseUserId,    // Database userID
        strAppLogDatabasePassword;  // Database password

    //-----------------------------------------------------------------------------------
    //
    //  Application logfile database table and field names
    //
    QString
        strAppLogTblNameApplicationLog    = "application_log",
        strAppLogFldAplRecId              = "apl_log_rec_id",
        strAppLogFldAplApplicationName    = "apl_log_application_name",
        strAppLogFldAplTimeStamp          = "apl_log_time_stamp",
        strAppLogFldAplLogSeverity        = "apl_log_severity",
        strAppLogFldAplLogMessage         = "apl_log_message";

    QStringList stlAplLogTables;

};

#endif // EUAPPLICATIONLOGGING_H


#ifndef QSQLQUERYMODEL_H
#define QSQLQUERYMODEL_H


/**
  * class QSqlQueryModel
  * 
  */

class QSqlQueryModel
{
public:
  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  QSqlQueryModel();

  /**
   * Empty Destructor
   */
  virtual ~QSqlQueryModel();

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //

protected:
  // Static Protected attributes
  //  

  // Protected attributes
  //  


  // Protected attribute accessor methods
  //  


  // Protected attribute accessor methods
  //

private:
  // Static Private attributes
  //  

  // Private attributes
  //  


  // Private attribute accessor methods
  //  


  // Private attribute accessor methods
  //

};

#endif // QSQLQUERYMODEL_H
