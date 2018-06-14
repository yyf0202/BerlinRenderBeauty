
#include "Image.h"
#include <soil.h>

NS_RENDER_BEGIN

void Image::Load(string_t path)
{
	int width, height;

	byte_t* data = nullptr;
	data = SOIL_load_image(path.c_str(), &width, &height, 0, SOIL_LOAD_AUTO);
	if (data == nullptr) return;

	auto img = new Image();
	img->SetData(data);

	return;
}

NS_RENDER_END