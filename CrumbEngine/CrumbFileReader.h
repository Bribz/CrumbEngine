
// CrumbFileReader.h
// File Reader and manager
// Bribz - 3/4/2017

#ifndef CRUMB_FILE_READER_H
#define CRUMB_FILE_READER_H

#include <string>
#include <vector>
using namespace std;

class CrumbFileReader
{
public:
	

	static vector<const char*> GetShaderPaths(const char * fileName);

	static const char* ReadShader(const char* filePath);

private:
	//const char* BaseShaderFilePath = "$(ProjectDir)\Shaders";

	CrumbFileReader();
	~CrumbFileReader();
};

#endif // !CRUMB_FILE_READER_H
