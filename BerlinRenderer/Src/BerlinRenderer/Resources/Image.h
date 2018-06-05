#pragma once

#include <BerlinRenderer/Base/Config.h>

NS_RENDER_BEGIN

class Image
{
public:
	inline byte_t * GetData() { return data_; }
	inline void SetData(byte_t* data) { data_ = data; }

private:
	byte_t * data_ = nullptr;
};

NS_RENDER_END