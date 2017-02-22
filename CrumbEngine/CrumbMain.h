
// CrumbMain.h
// Main entry point/object managing game loop
// Bribz - 2/22/2017

#ifndef CRUMB_MAIN
#define CRUMB_MAIN

#include "CrumbCore.h"
#include "CrumbGLWindow.h"

class CrumbMain
{
public:
	CrumbMain();
	~CrumbMain();

	void Shutdown();

private:
	bool running;
	CrumbGLWindow *Game_Window;

	void Loop();

};

#endif

