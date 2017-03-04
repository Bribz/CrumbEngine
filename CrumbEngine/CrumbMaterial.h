#ifndef CRUMB_MATERIAL_H
#define CRUMB_MATERIAL_H

#include "CrumbShader.h"
#include <vector>

class CrumbMaterial
{
public:
	CrumbMaterial(const char* sName);
	~CrumbMaterial();

	GLuint CreateShaderProgram();
	
private:
	std::vector<CrumbShader*>* shaders;
	const char* materialName;
	GLuint sProgramID;

	void Initialize_ShaderFiles();
};

#endif // !CRUMB_MATERIAL_H