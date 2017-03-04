
// CrumbShader.h
// Shader Management for Engine
// Bribz - 3/4/2017

#ifndef CRUMBSHADER_H
#define CRUMBSHADER_H

#include <GL\glew.h>
#include "CrumbEnumerations.h"

class CrumbShader
{
public:
	CrumbShader(const char* sName, const char* sFile, GLShaderType sType);
	~CrumbShader();

	GLuint pShader;
	const char* shaderName;
	
	GLuint LoadShader();
private: 
	const char* shaderFILE;
	GLShaderType SHADER_TYPE;

	GLenum DefineShaderType();

};

#endif
