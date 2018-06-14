#pragma once

#include <BerlinRenderer/Base/Config.h>

NS_RENDER_BEGIN

class StringUtil
{
public:
	template<typename... Args>
	static string_t Format(const char* fmt, Args... args)
	{
		if (sizeof...(Args) == 0) return fmt;

		static char s_tmp_buffer[1024];
		sprintf_s(s_tmp_buffer, fmt, args...);

		return s_tmp_buffer;
	}
};

NS_RENDER_END