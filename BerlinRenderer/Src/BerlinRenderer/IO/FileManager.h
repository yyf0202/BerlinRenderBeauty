#pragma once

#include <BerlinRenderer/Base/Config.h>
#include <BerlinRenderer/Base/Singleton.h>

NS_RENDER_BEGIN

class FileManager : public Singleton<FileManager>
{
public:
	string_t Read(string_t path);

private:
};

NS_RENDER_END