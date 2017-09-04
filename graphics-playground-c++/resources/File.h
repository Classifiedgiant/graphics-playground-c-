#pragma once

#include <fstream>
#include <string>

namespace App
{
	class File
	{
	public:
		File(std::string path, std::ios_base::open_mode file_mode);
		~File();

		std::string ReadContent();

		void Close();

	private:
		std::string _path;
		std::ifstream _file_stream;
		std::ios_base::open_mode _file_mode;
	};
}