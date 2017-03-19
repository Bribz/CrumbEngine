#pragma message("PROJECT_LOCATION == " PROJECT_LOCATION)

#include "CrumbFileReader.h"

#include <Windows.h>

#include <iostream>
#include <fstream>

#include <string>
#include <stdio.h>




CrumbFileReader::CrumbFileReader()
{

}


CrumbFileReader::~CrumbFileReader()
{

}

//TODO: Handle this to manage cross-platform file reads
std::vector<string> CrumbFileReader::GetShaderPaths(const char * fileName)
{
	std::vector<string> filenames;
	std::string search_path = PROJECT_LOCATION;
	search_path += "\Shaders\\" + std::string(fileName) + ".*";

	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(std::wstring(search_path.begin(), search_path.end()).c_str(), &fd);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			// read all (real) files in current folder
			// , delete '!' read other 2 default folder . and ..
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				char mbstr[260];
				wcstombs(mbstr, fd.cFileName, 260);
				string tmp = PROJECT_LOCATION;
				tmp += +"\Shaders\\";
				tmp += mbstr;
				filenames.push_back(tmp);
			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}
	else
	{
		//FAILED TO FIND SHADER FILES
		printf("[ Fatal Error ] : Failed to find files!\n--Path : %s\n", search_path.c_str());
		printf("--Shader Name : %s\n", fileName);
	}
	return filenames;
}

string CrumbFileReader::ReadShader(const char * filePath)
{
	
	std::string content;
	std::ifstream fileStream(filePath, std::ios::in);

	if (!fileStream.is_open()) {
		std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
		return "";
	}

	std::string line = "";
	while (!fileStream.eof()) {
		std::getline(fileStream, line);
		content.append(line + "\n");
	}

	fileStream.close();
	return content;
}
