#pragma once

#include <BerlinRenderer/Base/Config.h>
#include "Loader/ImageLoader.h"
#include "Resource.h"

NS_RENDER_BEGIN

class Image : public Resource
{
public:
	inline byte_t * GetData() { return data_; }
	inline void SetData(byte_t* data) { data_ = data; }

	virtual void Load(string_t path) override;

private:
	byte_t * data_ = nullptr;
};

NS_RENDER_END