#include "CrumbShader.h"
#include <stdio.h>
#include <vector>
#include <algorithm>

CrumbShader::CrumbShader(const char* sName, const char* sFile, GLShaderType sType)
{
	size_t len = strlen(sName) + 1;
	shaderName = new char[len];
	strcpy_s(shaderName, len, sName);

	len = strlen(sFile) + 1;
	shaderFILE = new char[len];
	strcpy_s(shaderFILE, len, sFile);

	SHADER_TYPE = sType;
}

CrumbShader::~CrumbShader()
{
	delete shaderFILE;
}

GLenum CrumbShader::DefineShaderType()
{
	GLenum retType = GL_VERTEX_SHADER;
	switch (SHADER_TYPE)
	{
		case GLShaderType::COMPUTE:
		{
			retType == GL_COMPUTE_SHADER;
			break;
		}
		case GLShaderType::FRAGMENT:
		{
			retType == GL_FRAGMENT_SHADER;
			break;
		}
		case GLShaderType::GEOMETRY:
		{
			retType == GL_GEOMETRY_SHADER;
			break;
		}
		case GLShaderType::VERTEX:
		{
			retType == GL_VERTEX_SHADER;
			break;
		}
		case GLShaderType::TESSELLATION:
		{
			printf("ERROR: Undefined Tesselation shader handling!");
		}
		case GLShaderType::NULL_TYPE:
		default:
		{
			retType = GL_INVALID_ENUM;
			break;
		}
	}
	return retType;
}


GLuint CrumbShader::LoadShader()
{
	GLuint nShader = glCreateShader(DefineShaderType());
	GLchar shaderErrors[512];
	GLsizei errorCount;

	// Read shaders

	GLint result = GL_FALSE;
	//int logLength;

	printf("Compiling Shader : %s\n", shaderName);
	glShaderSource(nShader, 1, &shaderFILE, NULL);
	glCompileShader(nShader);

	// Check vertex shader
	glGetShaderiv(nShader, GL_COMPILE_STATUS, &result);
	//glGetShaderiv(nShader, GL_INFO_LOG_LENGTH, &logLength);
	//std::vector vertShaderError((logLength > 1) ? logLength : 1);
	//glGetShaderInfoLog(nShader, logLength, &errorCount, shaderErrors);
	
	if (!result)
	{
		glGetShaderInfoLog(nShader, 512, NULL, shaderErrors);
		printf("SHADER_LOADING_ERROR : %s\n", shaderErrors);
	}

	pShader = nShader;
	return nShader;
}
