
#include "Image.h"
#include <soil.h>

NS_RENDER_BEGIN

void Image::Load(string_t path)
{
	data_ = SOIL_load_image(path.c_str(), &width_, &height_, 0, SOIL_LOAD_RGB);
	if (data_ == nullptr) return;

	return;
}

NS_RENDER_END