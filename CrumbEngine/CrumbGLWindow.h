
// CrumbGLWindow.h
// OpenGL/SDL Context for the rendered window
// - Some data may be remaining for testing purposes
// - SDL2 and OpenGL Boilerplate Code
// - Standard window opening
// Bribz - 2/22/2017

#ifndef CRUMB_GL_WINDOW
#define CRUMB_GL_WINDOW

#include "CrumbCore.h"

class CrumbGLWindow
{
public:
	SDL_Window	*Main_Window;
	SDL_GLContext glContext;

	CrumbGLWindow();
	~CrumbGLWindow();

	void GLDraw();

private:
	GLfloat verts[25] =
	{
		0.0f,  0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 1.0,
		0.0f, 1.0f, 0.0f,
		-1.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		-1.0f, -1.0f,
		0.0f, 0.0f, 0.0f,
		1.0f, -1.0f,
		0.0f, 0.0f, 0.0f
	};

	GLuint indices[6] = 
	{ 
		0, 1, 2, 
		0, 3, 4 
	};

	bool InitializeContext();
	bool SetOGLAttributes();
	void CheckSDLError(int line);
	
};

#endif
