#include "CrumbShader.h"
#include <stdio.h>
#include <vector>
#include <algorithm>

CrumbShader::CrumbShader(const char* sName, const char* sFile, GLShaderType sType)
{
	shaderName = sName;
	shaderFILE = sFile;
	SHADER_TYPE = sType;
}

CrumbShader::~CrumbShader()
{
	delete shaderFILE;
	delete shaderName;
}

GLenum CrumbShader::DefineShaderType()
{
	GLenum retType;
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
	GLchar* shaderErrors;
	GLsizei errorCount;

	// Read shaders

	GLint result = GL_FALSE;
	int logLength;

	printf("Compiling Shader : %s", shaderName);
	glShaderSource(nShader, 1, &shaderFILE, NULL);
	glCompileShader(nShader);

	// Check vertex shader
	glGetShaderiv(nShader, GL_COMPILE_STATUS, &result);
	glGetShaderiv(nShader, GL_INFO_LOG_LENGTH, &logLength);
	//std::vector vertShaderError((logLength > 1) ? logLength : 1);
	glGetShaderInfoLog(nShader, logLength, &errorCount, shaderErrors);
	
	if (errorCount > 0)
	{
		printf("SHADER_LOADING_ERROR : %s", shaderErrors);
	}

	pShader = nShader;
	return nShader;
}
