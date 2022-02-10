//---------------------------------------------------------------------------------------
//
//	LibRegistry.h
//
//---------------------------------------------------------------------------------------
#pragma once

//---------------------------------------------------------------------------------------
//
//	Header files
//
//---------------------------------------------------------------------------------------
using namespace std;// needed for default header files
#include <string>
#include <Windows.h>
//#include <stdio.h>
//#include <tchar.h>


class LibRegistry
{
public:
	LibRegistry(string &strAplicationDomain, string &strAplicationName);
	int GetRegistryKeyValue(
		const string &strSection,
		const string &strKey,
		string &strRegKeyValue);

private:
	int GetRegistryKeyValue(
		const string &strSection,
		const string &strKey);

	//-----------------------------------------------------------------------------------
	//
	//	Application registry variables
	//
	long
		iRegistryKeyValue;	// Possible value of the key

	string
		strAplDomain,		// Application domain name
		strAplName,			// Application name
		strRegistryKeyValue;// Possible value of the key


	void QueryKey(HKEY hKey);

};

