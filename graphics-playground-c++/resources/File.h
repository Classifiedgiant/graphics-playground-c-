#pragma once

#include <string>

namespace App
{
	class File
	{
	public:
		File(std::string path);
		~File();

		std::string ReadContent();

	private:
		std::string _path;
		//std::ifstream _fileMode; 
	};
}