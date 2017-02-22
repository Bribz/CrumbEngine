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

