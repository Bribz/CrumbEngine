
// CrumbMain.h
// Main entry point/object managing game loop
// Bribz - 2/22/2017

#include "CrumbMain.h"

CrumbMain::CrumbMain()
{
	printf("Launching CrumbEngine...\n");
	
	running = true;

	//Launch Game Window
	Game_Window = new CrumbGLWindow();

	Loop();

}

void CrumbMain::Loop()
{
	bool running = true;

	while (running)
	{
		SDL_Event event;

		//Handle SDL_Events
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}

			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					running = false;
					break;
				default:
					break;
				}
			}
		}

		//Handle DrawCalls
		Game_Window->GLDraw();
	}

	Shutdown();
}

void CrumbMain::Shutdown()
{
	printf("Shutting down CrumbEngine...\n");
	
	running = false;
	
	delete Game_Window;

	SDL_Quit();

	
}

CrumbMain::~CrumbMain()
{
	if (running)
	{
		Shutdown();
	}
}


