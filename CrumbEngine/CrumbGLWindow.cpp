// CrumbGLWindow.h
// OpenGL/SDL Context for the rendered window
// - Some data may be remaining for testing purposes
// - SDL2 and OpenGL Boilerplate Code
// - Standard window opening
// Bribz - 2/22/2017

#include "CrumbGLWindow.h"

CrumbGLWindow::CrumbGLWindow()
{
	InitializeContext();
	//TODO: Return -1 if false

	// TEMP: Clear buffer, black background
	glClearColor(1.0, 0.0, 0.5, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(Main_Window);

	//Generate Buffer
	GLuint vertexbufferID;
	glGenBuffers(1, &vertexbufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (char*)(sizeof(float) * 2));

	GLuint indexBufferID;
	glGenBuffers(1, &indexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

}


CrumbGLWindow::~CrumbGLWindow()
{
	SDL_GL_DeleteContext(glContext);

	SDL_DestroyWindow(Main_Window); 
}

bool CrumbGLWindow::InitializeContext()
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

bool CrumbGLWindow::SetOGLAttributes()
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

void CrumbGLWindow::CheckSDLError(int line = -1)
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



void CrumbGLWindow::GLDraw()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	//Draw Objects
	//glDrawArrays(GL_TRIANGLES, 0, 6);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	SDL_GL_SwapWindow(Main_Window);
}

