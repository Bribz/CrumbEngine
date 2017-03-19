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
	//delete materialName;
}

void CrumbMaterial::Initialize_ShaderFiles()
{
	std::vector<string> filePaths = CrumbFileReader::GetShaderPaths(materialName);
	
	for (auto name : filePaths)
	{
		printf("Found file : %s\n", name.c_str());
	}
	

	for (auto path : filePaths)
	{
		//memcpy(shadChar, (void*)path[strlen(path-1)], 1);
		
		string shaderFile = CrumbFileReader::ReadShader(path.c_str());

		shaders->push_back(new CrumbShader(materialName, shaderFile.c_str(), (GLShaderType)path[path.length() - 1]));
	}
}

//TODO: Handle Errors
GLuint CrumbMaterial::CreateShaderProgram()
{
	GLchar programErrors[512];
	GLint result = GL_FALSE;
	printf("Linking shader program %s \n", materialName );

	GLuint program = glCreateProgram();
	for (auto shader : *shaders)
	{
		glAttachShader(program, shader->LoadShader());
	}
	
	glLinkProgram(program);

	glGetProgramiv(program, GL_LINK_STATUS, &result);
	//glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
	//std::vector<char> programError((logLength > 1) ? logLength : 1);
	//std::cout << &programError[0] << std::endl;
	if (!result)
	{
		glGetProgramInfoLog(program, 512, NULL, programErrors);
	}


	for (auto it = shaders->begin(); it != shaders->end(); ++it) 
	{
		glDeleteShader((*it)->pShader);
	}

	sProgramID = program;
	return program;
}

