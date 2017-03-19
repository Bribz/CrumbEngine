
// CrumbGLWindow.h
// OpenGL/SDL Context for the rendered window
// - Some data may be remaining for testing purposes
// - SDL2 and OpenGL Boilerplate Code
// - Standard window opening
// Bribz - 2/22/2017

#ifndef CRUMB_GL_WINDOW
#define CRUMB_GL_WINDOW

#include "CrumbCore.h"
#include "DataManager.h"

class CrumbGLWindow
{
public:
	DataManager * Data_Manager;
	SDL_Window	*Main_Window;
	SDL_GLContext glContext;

	CrumbGLWindow(DataManager* dataManager);
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
		1.0f, 1.0f, 1.0f,
		1.0f, -1.0f,
		1.0f, 1.0f, 1.0f
	};

	GLuint indices[6] = 
	{ 
		0, 1, 2, 
		0, 3, 4 
	};

	bool InitializeContext();
	bool SetOGLAttributes();
	void CheckSDLError(int line);


	void LoadOpenGLData();



	//TODO: Get rid of this crap temp code

	GLuint programID;

	const char* vertShaderCode =
		"#version 430\r\n"
		""
		"in layout(location=0) vec2 position;"
		"in layout(location=1) vec3 vertexColor;"
		"out vec3 vColor;"
		""
		"void main()"
		"{"
		"	gl_Position = vec4(position, 0.0, 1.0);"
		"	vColor = vertexColor;"
		"}";

	const char* fragShaderCode =
		"#version 430\r\n"
		""
		"out vec4 colorOut;"
		"in vec3 vColor;"
		""
		"void main()"
		"{"
		"	colorOut = vec4(vColor, 1.0);"
		"}";
};

#endif
