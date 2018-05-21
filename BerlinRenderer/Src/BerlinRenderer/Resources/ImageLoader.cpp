
#include "ImageLoader.h"

NS_RENDER_BEGIN

ImageLoader::ImageLoader()
{

}

ImageLoader::~ImageLoader()
{

}

ImageLoader& ImageLoader::getInstance()
{
	static ImageLoader instance;
	return instance;
}

Texture2D* ImageLoader::Load(string_t path, int32_t width, int32_t height, int32_t format)
{
	// TODO:
	//return SOIL_load_image(path.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
	return nullptr;
}

NS_RENDER_END