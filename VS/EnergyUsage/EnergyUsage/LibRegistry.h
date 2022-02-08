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
		string &strRegistryKeyValue);

private:
	int GetRegistryKeyValue(
		const string &strSection,
		const string &strKey,
		string &strRegistryKeyValue,
		int &iRegistryValue);

	string
		strAplDomain,
		strAplName;


	void QueryKey(HKEY hKey);

};

