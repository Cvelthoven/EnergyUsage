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
//using namespace std;// needed for default header files
#include <Windows.h>
//#include <stdio.h>
//#include <tchar.h>


class LibRegistry
{
public:
	LibRegistry();
	void GetRegistryKeyValue(HKEY hKey);
	void QueryKey(HKEY hKey);

};

