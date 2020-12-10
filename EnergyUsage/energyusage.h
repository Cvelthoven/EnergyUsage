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
    strDatabaseSection      = "AplDatabase",        // Database section name
    strKeyDbServerName = "AplDatabaseServerName",   // Key name with database server name
    strDatabaseServerNameDef = "192.168.1.51",      // Default database server
    //-------------------------------------------------------------------------------
    strKeyDbName = "AplDatabaseName",               // Key name with database name
    strDatabaseNameDef = "cvraspi01dev",            // Default database name
    //-------------------------------------------------------------------------------
    strKeyDbUserId = "AplDatabaseUserId",           // Key name with database UserID
    strDatabaseUserIdDef = "pi",                    // Default database UserID
    //-------------------------------------------------------------------------------
    strKeyDbPassword = "AplDatabasePassword",       // Key name with database Password
    strDatabasePasswordDef = "#NS01fr#LDrz76#";     // Default database Password

#endif // ENERGYUSAGE_H
