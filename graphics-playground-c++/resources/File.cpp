#include "stdafx.h"
#include "File.h"
#include <fstream>

namespace App 
{
	File::File(std::string path)
	: _path(path)
	//, _fileMode(fileMode)
	{
	}
	

	File::~File()
	{

	}

	std::string File::ReadContent()
	{
		std::ifstream fileStream(_path);

		std::string contents((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
		return contents;
	}
}