#include "MainWindow.h"
#include "LibRegistry.h"
#include <string>

//---------------------------------------------------------------------------------------
//
//	Constructors
MainWindow::MainWindow()
{
	InitProgram();
}

//---------------------------------------------------------------------------------------
//
//	Functions
//
//---------------------------------------------------------------------------------------
//
//	InitProgram
//
//---------------------------------------------------------------------------------------
void MainWindow::InitProgram()
{
	string
		strDomain = "CVelthoven.com",
		strApplicantion = "EnergyUsage";

	LibRegistry* appSettings = new LibRegistry(strDomain, strApplicantion);
}