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
	string GetRegistryKeyValue(const string strAppDomain,
							 const string strAppName,
							 const string strSection,
							 const string strKey);

	void QueryKey(HKEY hKey);

};

