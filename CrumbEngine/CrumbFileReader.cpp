#include "CrumbFileReader.h"

#include <Windows.h>

#include <iostream>
#include <fstream>

#include <string>




CrumbFileReader::CrumbFileReader()
{

}


CrumbFileReader::~CrumbFileReader()
{

}

//TODO: Handle this to manage cross-platform file reads
std::vector<const char*> CrumbFileReader::GetShaderPaths(const char * fileName)
{
	std::vector<const char*> filenames;
	std::string search_path = "$(ProjectDir)/Shaders/" + std::string(fileName) + ".*";

	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(std::wstring(search_path.begin(), search_path.end()).c_str(), &fd);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			// read all (real) files in current folder
			// , delete '!' read other 2 default folder . and ..
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				char mbstr[260];
				wcstombs(mbstr, fd.cFileName, 260);
				filenames.push_back(mbstr);
			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}
	return filenames;
}

const char* CrumbFileReader::ReadShader(const char * filePath)
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
	return content.c_str();
}
