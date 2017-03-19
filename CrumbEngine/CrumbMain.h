
// CrumbMain.h
// Main entry point/object managing game loop
// Bribz - 2/22/2017

#ifndef CRUMB_MAIN
#define CRUMB_MAIN

#include "CrumbCore.h"
#include "CrumbGLWindow.h"
#include "DataManager.h"

class CrumbMain
{
public:
	CrumbMain();
	~CrumbMain();

	void Shutdown();

private:
	DataManager* Data_Manager;
	CrumbGLWindow *Game_Window;
	bool running;

	void Loop();

};

#endif

