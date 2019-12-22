//---------------------------------------------------------------------------------------
//
//  euapplicationlogging
//
//  This class handles all application logging to a database or file
//
#include "euapplicationlogging.h"

//---------------------------------------------------------------------------------------
//
//  Default constructor
//
euApplicationLogging::euApplicationLogging(QObject *parent)
{
    //-----------------------------------------------------------------------------------
    //
    //  Retrieve application logging configuration
    euRetrieveLogConfig();

}

//---------------------------------------------------------------------------------------
//
//  Retrieve application logging configuration
//
void euApplicationLogging::euRetrieveLogConfig()
{

}
