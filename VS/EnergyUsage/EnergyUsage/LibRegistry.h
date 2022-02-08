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
	LibRegistry();
	int GetRegistryKeyValue(const string &strAppDomain,
		const string &strAppName,
		const string &strSection,
		const string &strKey,
		string &strRegistryKeyValue);

private:
	int GetRegistryKeyValue(const string &strAppDomain,
		const string &strAppName,
		const string &strSection,
		const string &strKey,
		string &strRegistryKeyValue,
		int &iRegistryValue);

	void QueryKey(HKEY hKey);

};

