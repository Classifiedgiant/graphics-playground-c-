#include "stdafx.h"
#include "File.h"

namespace App 
{
	File::File(std::string path, std::ios_base::open_mode file_mode)
		: _path(path)
		, _file_stream(_path, file_mode)
		, _file_mode(file_mode)
	{
		if (!_file_stream.good())
			throw;
	}
	
	File::~File()
	{
		if (_file_stream.is_open())
			_file_stream.close();
	}

	std::string File::ReadContent()
	{
		std::string contents((std::istreambuf_iterator<char>(_file_stream)), std::istreambuf_iterator<char>());
		return contents;
	}

	void File::Close()
	{
		_file_stream.close();
	}
}