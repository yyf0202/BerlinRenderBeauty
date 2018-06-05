
#include "FileManager.h"

#include <fstream>
#include <sstream>
#include <iostream>

NS_RENDER_BEGIN

string_t FileManager::Read(string_t path)
{
	std::ifstream file;

	file.open(path);
	std::stringstream stream;
	stream << file.rdbuf();

	return stream.str();
}

NS_RENDER_END