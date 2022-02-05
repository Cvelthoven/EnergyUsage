//---------------------------------------------------------------------------------------
//
//	MainWindow
// 
// Support info:
//
//---------------------------------------------------------------------------------------
//
//	Headers
//
//---------------------------------------------------------------------------------------
#include "LibRegistry.h"
#include <string>
#include <Windows.h>
//---------------------------------------------------------------------------------------
//	Example header files and defines

#include <stdio.h>
#include <tchar.h>

#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383

//---------------------------------------------------------------------------------------
//
//	Constructors
LibRegistry::LibRegistry()
{
	const string strDomain	= "CVelthoven.com",
				 strAppl	= "EnergyUsage",
				 strSection = "",
				 strKey     = "Test01";
	string temp;

		temp = GetRegistryKeyValue(strDomain, strAppl,strSection,strKey);
}

//---------------------------------------------------------------------------------------
//
//	Public class methodes
//
//---------------------------------------------------------------------------------------
//
//	GetRegistryKeyValue
//	- input:
//		- strAppDomain
//		- strAppName
//		- strSection
//		- strKey
//
//---------------------------------------------------------------------------------------
string LibRegistry::GetRegistryKeyValue(const string strAppDomain, 
									  const string strAppName,
									  const string strSection,
									  const string strKey)
{
	//-----------------------------------------------------------------------------------
	//
	//	Local variables
	wchar_t KeyValue[255];
	DWORD KeyValueLen = sizeof(KeyValue);
	string 
		strSubKey,
		strKeyValue;
	LPCWSTR 
		lpSubKey,
		lpKey;

	//-----------------------------------------------------------------------------------
	//
	//	Convert input strings to LPCSTR required in RegGetValue
	//
	strSubKey = "SOFTWARE\\" + strAppDomain + "\\" + strAppName;
	if (strSection.length() > 0)
	{
		strSubKey = strSubKey + "\\" + strSection;
	}

	std::wstring temp = std::wstring(strSubKey.begin(), strSubKey.end());
	lpSubKey = temp.c_str();
	std::wstring temp2 = std::wstring(strKey.begin(), strKey.end());
	lpKey = temp2.c_str();

	//-----------------------------------------------------------------------------------
	//
	//	Retrieve key value
	//
	if (RegGetValue(
				HKEY_CURRENT_USER,
				lpSubKey,
				lpKey,
				RRF_RT_ANY,
				NULL,
				(PVOID)&KeyValue,
				&KeyValueLen
	)	 == ERROR_SUCCESS)

	//-----------------------------------------------------------------------------------
	//
	//	Return value of key
    //
	{
		char strTemp[255];
		char DefChar = ' ';
		WideCharToMultiByte(CP_ACP, 0, KeyValue, -1, strTemp, 255, &DefChar, NULL);
		std::string strTemp2(strTemp);
		strKeyValue = strTemp2;

	}
	//-----------------------------------------------------------------------------------
	//
	//	Return empty string as error result
	//
	else
	{
		strKeyValue = "";
	}
	return(strKeyValue);
}

//-----------------------------------------------------------------------------
//
//	QueryKey
//
//	Input:
//		- hKey: root to applications settings
//
//-----------------------------------------------------------------------------
void LibRegistry::QueryKey(HKEY hKey)
{
	    TCHAR    achKey[MAX_KEY_LENGTH];   // buffer for subkey name
	    DWORD    cbName;                   // size of name string 
	    TCHAR    achClass[MAX_PATH] = TEXT("");  // buffer for class name 
	    DWORD    cchClassName = MAX_PATH;  // size of class string 
	    DWORD    cSubKeys = 0;               // number of subkeys 
	    DWORD    cbMaxSubKey;              // longest subkey size 
	    DWORD    cchMaxClass;              // longest class string 
	    DWORD    cValues;              // number of values for key 
	    DWORD    cchMaxValue;          // longest value name 
	    DWORD    cbMaxValueData;       // longest value data 
	    DWORD    cbSecurityDescriptor; // size of security descriptor 
	    FILETIME ftLastWriteTime;      // last write time 
	
	    DWORD i, retCode;
	
	    TCHAR  achValue[MAX_VALUE_NAME];
	    DWORD cchValue = MAX_VALUE_NAME;
	
	    // Get the class name and the value count. 
	    retCode = RegQueryInfoKey(
	        hKey,                    // key handle 
	        achClass,                // buffer for class name 
	        &cchClassName,           // size of class string 
	        NULL,                    // reserved 
	        &cSubKeys,               // number of subkeys 
	        &cbMaxSubKey,            // longest subkey size 
	        &cchMaxClass,            // longest class string 
	        &cValues,                // number of values for this key 
	        &cchMaxValue,            // longest value name 
	        &cbMaxValueData,         // longest value data 
	        &cbSecurityDescriptor,   // security descriptor 
	        &ftLastWriteTime);       // last write time 
	
	    // Enumerate the subkeys, until RegEnumKeyEx fails.
	
	    if (cSubKeys)
	    {
	        printf("\nNumber of subkeys: %d\n", cSubKeys);
	
	        for (i = 0; i < cSubKeys; i++)
	        {
	            cbName = MAX_KEY_LENGTH;
	            retCode = RegEnumKeyEx(hKey, i,
	                achKey,
	                &cbName,
	                NULL,
	                NULL,
	                NULL,
	                &ftLastWriteTime);
	            if (retCode == ERROR_SUCCESS)
	            {
	                _tprintf(TEXT("(%d) %s\n"), i + 1, achKey);
	            }
	        }
	    }
	
	    // Enumerate the key values. 
	
		if (cValues)
		{
			printf("\nNumber of values: %d\n", cValues);

			for (i = 0, retCode = ERROR_SUCCESS; i < cValues; i++)
			{
				cchValue = MAX_VALUE_NAME;
				achValue[0] = '\0';
				retCode = RegEnumValue(hKey, i,
					achValue,
					&cchValue,
					NULL,
					NULL,
					NULL,
					NULL);

				if (retCode == ERROR_SUCCESS)
				{
					_tprintf(TEXT("(%d) %s\n"), i + 1, achValue);

				}
			}
		}

}


//---------------------------------------------------------------------------------------------------------------
// Example code copy
// QueryKey - Enumerates the subkeys of key and its associated values.
//     hKey - Key whose subkeys and values are to be enumerated.
//
//#include <windows.h>
//#include <stdio.h>
//#include <tchar.h>
//
//#define MAX_KEY_LENGTH 255
//#define MAX_VALUE_NAME 16383
//
//void QueryKey(HKEY hKey)
//{
//    TCHAR    achKey[MAX_KEY_LENGTH];   // buffer for subkey name
//    DWORD    cbName;                   // size of name string 
//    TCHAR    achClass[MAX_PATH] = TEXT("");  // buffer for class name 
//    DWORD    cchClassName = MAX_PATH;  // size of class string 
//    DWORD    cSubKeys = 0;               // number of subkeys 
//    DWORD    cbMaxSubKey;              // longest subkey size 
//    DWORD    cchMaxClass;              // longest class string 
//    DWORD    cValues;              // number of values for key 
//    DWORD    cchMaxValue;          // longest value name 
//    DWORD    cbMaxValueData;       // longest value data 
//    DWORD    cbSecurityDescriptor; // size of security descriptor 
//    FILETIME ftLastWriteTime;      // last write time 
//
//    DWORD i, retCode;
//
//    TCHAR  achValue[MAX_VALUE_NAME];
//    DWORD cchValue = MAX_VALUE_NAME;
//
//    // Get the class name and the value count. 
//    retCode = RegQueryInfoKey(
//        hKey,                    // key handle 
//        achClass,                // buffer for class name 
//        &cchClassName,           // size of class string 
//        NULL,                    // reserved 
//        &cSubKeys,               // number of subkeys 
//        &cbMaxSubKey,            // longest subkey size 
//        &cchMaxClass,            // longest class string 
//        &cValues,                // number of values for this key 
//        &cchMaxValue,            // longest value name 
//        &cbMaxValueData,         // longest value data 
//        &cbSecurityDescriptor,   // security descriptor 
//        &ftLastWriteTime);       // last write time 
//
//    // Enumerate the subkeys, until RegEnumKeyEx fails.
//
//    if (cSubKeys)
//    {
//        printf("\nNumber of subkeys: %d\n", cSubKeys);
//
//        for (i = 0; i < cSubKeys; i++)
//        {
//            cbName = MAX_KEY_LENGTH;
//            retCode = RegEnumKeyEx(hKey, i,
//                achKey,
//                &cbName,
//                NULL,
//                NULL,
//                NULL,
//                &ftLastWriteTime);
//            if (retCode == ERROR_SUCCESS)
//            {
//                _tprintf(TEXT("(%d) %s\n"), i + 1, achKey);
//            }
//        }
//    }
//
//    // Enumerate the key values. 
//
//    if (cValues)
//    {
//        printf("\nNumber of values: %d\n", cValues);
//
//        for (i = 0, retCode = ERROR_SUCCESS; i < cValues; i++)
//        {
//            cchValue = MAX_VALUE_NAME;
//            achValue[0] = '\0';
//            retCode = RegEnumValue(hKey, i,
//                achValue,
//                &cchValue,
//                NULL,
//                NULL,
//                NULL,
//                NULL);
//
//            if (retCode == ERROR_SUCCESS)
//            {
//                _tprintf(TEXT("(%d) %s\n"), i + 1, achValue);
//            }
//        }
//    }
//}
//
//int __cdecl _tmain()
//{
//    HKEY hTestKey;
//
//    if (RegOpenKeyEx(HKEY_CURRENT_USER,
//        TEXT("SOFTWARE\\Microsoft"),
//        0,
//        KEY_READ,
//        &hTestKey) == ERROR_SUCCESS
//        )
//    {
//        QueryKey(hTestKey);
//    }
//
//    RegCloseKey(hTestKey);
//}