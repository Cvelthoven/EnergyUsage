//---------------------------------------------------------------------------------------
//
//	MainWindow.h
//
//---------------------------------------------------------------------------------------
#pragma once

//---------------------------------------------------------------------------------------
//
//	Header files
//
//---------------------------------------------------------------------------------------
using namespace std;// needed for default header files
#include "EnergyUsage.h"
#include "LibRegistry.h"
#include <string>

//---------------------------------------------------------------------------------------
//
//	MainWindow class definitions
//
//---------------------------------------------------------------------------------------
class MainWindow
{
public:
	MainWindow();
	~MainWindow();

private:
	void InitProgram();

	const string strAppName				= "EnergyUsage",
				strOrganizationDomain	= "CVelthoven.com",
				strOrganizationName		= "CVelthoven";

};
