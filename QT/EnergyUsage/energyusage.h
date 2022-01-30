#ifndef ENERGYUSAGE_H
#define ENERGYUSAGE_H
#include <QString>

const QString
    strApplicationName      = "EnergyUsage",
    strOrganizationDomain   = "CVelthoven.com",
    strOrganizationName     = "CVelthoven",
//-----------------------------------------------------------------------------
//
//  Application settings definitions
//
    strDatabaseSection  = "AplDatabase",          // Database section name
    strKeyDbServerName  = "AplDatabaseServerName",// Key name with database server name
    strKeyDbName        = "AplDatabaseName",      // Key name with database name
    strKeyDbUserId      = "AplDatabaseUserId",    // Key name with database UserID
    strKeyDbPassword    = "AplDatabasePassword",  // Key name with database Password

//-----------------------------------------------------------------------------
//
//  Application logging definitions
//
    strAppLogSectionName        = "Log",                   // Application logging section name
    strAppLogKeyLoggingType     = "LogType",               // Key name with the type of log (db or file)
    strAppLogKeyDbServerName    = "LogDatabaseServerName", // Key name with application logging database server name
    strAppLogKeyDbName          = "LogDatabaseName",       // Key name with database name
    strAppLogKeyDbUserId        = "LogDatabaseUserId",     // Key name with database UserID
    strAppLogKeyDbPassword      = "LogDatabasePassword";   // Key name with database Password

#endif // ENERGYUSAGE_H
