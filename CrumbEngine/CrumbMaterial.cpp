#include "CrumbMaterial.h"
#include "CrumbFileReader.h"
#include <stdio.h>
#include <vector>


CrumbMaterial::CrumbMaterial(const char* sName)
{
	materialName = sName;
	shaders = new std::vector<CrumbShader*>();
	Initialize_ShaderFiles();
}


CrumbMaterial::~CrumbMaterial()
{
	for (auto it = shaders->begin(); it != shaders->end(); ++it) 
	{
		delete *it;
	}

	shaders->clear();

	delete shaders;
	delete materialName;
}

void CrumbMaterial::Initialize_ShaderFiles()
{
	std::vector<const char*> filePaths = CrumbFileReader::GetShaderPaths(materialName);
	for (auto name : filePaths)
	{
		printf("Found file : %s", name);
	}

	for (auto path : filePaths)
	{
		char* shadChar;
		memcpy(shadChar, path, strlen(path)-1);

		const char* shaderFile = CrumbFileReader::ReadShader(path);

		shaders->push_back(new CrumbShader(materialName, shaderFile, (GLShaderType)*shadChar));
	}
}

//TODO: Handle Errors
GLuint CrumbMaterial::CreateShaderProgram()
{
	GLint result = GL_FALSE;
	printf("Linking shader program %s", materialName );

	GLuint program = glCreateProgram();
	for (auto shader : *shaders)
	{
		glAttachShader(program, shader->LoadShader());
	}
	
	glLinkProgram(program);

	glGetProgramiv(program, GL_LINK_STATUS, &result);
	//glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
	//std::vector<char> programError((logLength > 1) ? logLength : 1);
	//glGetProgramInfoLog(program, logLength, NULL, &programError[0]);
	//std::cout << &programError[0] << std::endl;

	for (auto it = shaders->begin(); it != shaders->end(); ++it) 
	{
		glDeleteShader((*it)->pShader);
	}

	sProgramID = program;
	return program;
}

