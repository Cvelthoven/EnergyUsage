//---------------------------------------------------------------------------------------
//
//  euapplicationlogging
//
//  This class handles all application logging to a database or file
//
#include "euapplicationlogging.h"
#include "euapplicationsettings.h"

#include <QMessageBox>

#include <QDebug>

//---------------------------------------------------------------------------------------
//
//  Default constructor
//
euApplicationLogging::euApplicationLogging(QObject *parent)
        : QStandardItemModel(parent)
{
    //-----------------------------------------------------------------------------------
    //
    //  Retrieve application logging configuration
    euAplLogingSettings = new euApplicationSettings();
    euRetrieveLogConfig();

}

//---------------------------------------------------------------------------------------
//
//  Retrieve application logging configuration
//
bool euApplicationLogging::euRetrieveLogConfig()
{
    bool
        bOK = true;

    int iStrlen;

    //-----------------------------------------------------------------------------------
    //
    //  Check type of logging
    //
    strAppLogLoggingType = euAplLogingSettings->euGetAppSetting(strAppLogSectionName, strAppLogKeyLoggingType);
    iStrlen = strAppLogLoggingType.length();
    if (iStrlen == 0)
    {
        bOK = euAplLogingSettings->euSetAppSetting(strAppLogSectionName,strAppLogKeyLoggingType,strAppLogLoggingTypeDef);
        if(!bOK)
            SendWarningMessage(strAppLogKeyLoggingType,"Unable to write to configuration.");
        strAppLogLoggingType = strAppLogLoggingTypeDef;
    }

    //-----------------------------------------------------------------------------------
    //
    //  Get datbase configuration
    //
    if (strAppLogLoggingType == "db")
    {
        //  Get database servername
        strAppLogDatabaseServerName = euAplLogingSettings->euGetAppSetting(strAppLogSectionName, strAppLogKeyDbServerName);
        iStrlen = strAppLogDatabaseServerName.length();
        if (iStrlen == 0)
        {
            bOK = euAplLogingSettings->euSetAppSetting(strAppLogSectionName,strAppLogKeyDbServerName,strAppLogDatabaseServerNameDef);
            if(!bOK)
                SendWarningMessage(strAppLogKeyLoggingType,"Unable to write to configuration.");
            strAppLogDatabaseServerName = strAppLogDatabaseServerNameDef;
        }
        //
        //  Get database name
        strAppLogDatabaseName = euAplLogingSettings->euGetAppSetting(strAppLogSectionName, strAppLogKeyDbName);
        iStrlen = strAppLogDatabaseName.length();
        if (iStrlen == 0)
        {
            bOK = euAplLogingSettings->euSetAppSetting(strAppLogSectionName,strAppLogKeyDbName,strAppLogDatabaseNameDef);
            if(!bOK)
                SendWarningMessage(strAppLogKeyDbName,"Unable to write to configuration.");
            strAppLogDatabaseName = strAppLogDatabaseNameDef;
        }
        //
        //  Get database Username
        strAppLogDatabaseUserId = euAplLogingSettings->euGetAppSetting(strAppLogSectionName, strAppLogKeyDbUserId);
        iStrlen = strAppLogDatabaseUserId.length();
        if (iStrlen == 0)
        {
            bOK = euAplLogingSettings->euSetAppSetting(strAppLogSectionName,strAppLogKeyDbUserId,strAppLogDatabaseUserIdDef);
            if(!bOK)
                SendWarningMessage(strAppLogKeyDbUserId,"Unable to write to configuration.");
            strAppLogDatabaseUserId = strAppLogDatabaseUserIdDef;
        }
        //
        //  Get database Password
        strAppLogDatabasePassword = euAplLogingSettings->euGetAppSetting(strAppLogSectionName, strAppLogKeyDbPassword);
        iStrlen = strAppLogDatabasePassword.length();
        if (iStrlen == 0)
        {
            bOK = euAplLogingSettings->euSetAppSetting(strAppLogSectionName,strAppLogKeyDbPassword,strAppLogDatabasePasswordDef);
            if(!bOK)
                SendWarningMessage(strAppLogKeyDbPassword,"Unable to write to configuration.");
            strAppLogDatabasePassword = strAppLogDatabasePasswordDef;
        }
        return(bOK);
    }
    else
    {
        //-------------------------------------------------------------------------------
        //
        //  Get log file configuration
        //
        if (strAppLogLoggingType == "file")
        {
            return false;
        }
        else
        //-------------------------------------------------------------------------------
        //
        //  Unknown log type defined
        //
        {
            return false;
        }
    }
}

//---------------------------------------------------------------------------------------
//
//  Display warning message log configuration
//
void euApplicationLogging::SendWarningMessage(const QString &strMsgPart1, const QString &strMsgPart2)
{
    QMessageBox msgBox;
    QString euMessage;

    euMessage = strMsgPart1 + ": " + strMsgPart2;
    msgBox.setText(euMessage);
    msgBox.exec();
    qDebug() << strMsgPart1 << ", " << strMsgPart2;


}
