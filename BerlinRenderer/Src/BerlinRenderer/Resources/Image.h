#pragma once

#include <BerlinRenderer/Base/Config.h>
#include "Resource.h"

NS_RENDER_BEGIN

class Image : public Resource
{
public:
	inline byte_t * GetData() { return data_; }
	inline void SetData(byte_t* data) { data_ = data; }

	virtual void Load(string_t path) override;

	inline int32_t GetWidth() { return width_; }
	inline int32_t GetHeight() { return height_; }

private:
	byte_t * data_ = nullptr;
	int32_t width_ = 0;
	int32_t height_ = 0;
};

NS_RENDER_END