// SDL2 and OpenGL Boilerplate Code
// Standard window opening

#include "CrumbMain.h"

/*
// printf and console dialogue
#include <stdio.h>

// OpenGL / glew
#define GL3_PROTOTYPES 1
#include <GL\glew.h>

// SDL2 Headers
#include <SDL2\SDL.h>


// Declaration Station
SDL_Window *Main_Window;

// SDL - OpenGL context handle
SDL_GLContext glContext;

void CheckSDLError(int line);
bool SetOGLAttributes();

bool InitializeContext()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Failed to init SDL!\n");
		return false;
	}

	//Create a Window
	Main_Window = SDL_CreateWindow(
		"CrumbEngine",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800,
		600,
		SDL_WINDOW_OPENGL
	);

	if (!Main_Window)
	{
		printf("Failed to create window!\n");
		CheckSDLError(__LINE__);
		return false;
	}

	//Create OGL context and attach to window
	glContext = SDL_GL_CreateContext(Main_Window);

	SetOGLAttributes();

	//Set buffer swap to synchronize with monitor vertical refresh rate
	SDL_GL_SetSwapInterval(1);

	// Additional details for Apple
	#ifndef __APPLE__
	glewExperimental = GL_TRUE;
	glewInit();
	#endif // !__APPLE__

	return true;
}

bool SetOGLAttributes()
{
	//Set OpenGL version
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	// Set Double Buffer with 24bit Z buffer;
	// TODO: ADJUST THIS LATER FOR CLIENT CHOICE
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	return true;
}

void Cleanup()
{
	SDL_GL_DeleteContext(glContext);

	SDL_DestroyWindow(Main_Window);

	SDL_Quit();
}

void CheckSDLError(int line = -1)
{
	const char* error = SDL_GetError();

	if (error != "")
	{
		printf("[SDL_Error] : %s", error);

		if (line != -1)
		{
			printf(" - <Line> : %i\n", line);
		}
		else
		{
			printf("\n");
		}

		SDL_ClearError();
	}
}

void TempLoop()
{
	bool running = true;

	while (running)
	{
		SDL_Event event;

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
	}
}

int main(int argc, char ** argv)
{
	if (!InitializeContext())
	{
		return -1;
	}

	// TEMP: Clear buffer, black background
	glClearColor(1.0, 0.0, 0.5, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(Main_Window);

	TempLoop();

	//Cleanup SDL stuff, quit program;
	Cleanup();
	
	return 0;
}
*/

int main(int argc, char ** argv)
{
	CrumbMain *game = new CrumbMain();

	delete game;

	return 0;
}
