
#include "Image.h"
#include <soil.h>

NS_RENDER_BEGIN

void Image::Load(string_t path)
{
	int width, height;

	data_ = SOIL_load_image(path.c_str(), &width, &height, 0, SOIL_LOAD_AUTO);
	if (data_ == nullptr) return;

	return;
}

NS_RENDER_END