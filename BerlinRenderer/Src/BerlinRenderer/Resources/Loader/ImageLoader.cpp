
#include "ImageLoader.h"
#include "../Image.h"

NS_RENDER_BEGIN

void ImageLoader::BeginTask()
{
	resource_ = Load(path_);
}

void ImageLoader::EndTask()
{
	loaded_(resource_);
}

Image* ImageLoader::Load(string_t path)
{
	int width, height;

	byte_t* data = nullptr;
	data = SOIL_load_image(path.c_str(), &width, &height, 0, SOIL_LOAD_AUTO);
	if (data == nullptr) return nullptr;

	auto img = new Image();
	img->SetData(data);

	return img;
}

NS_RENDER_END