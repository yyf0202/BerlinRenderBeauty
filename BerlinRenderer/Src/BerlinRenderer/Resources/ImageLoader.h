#pragma once
#include "soil.h"


enum
{
	TEXTURE_AUTO = 0,
	TEXTURE_L = 1,
	TEXTURE_LA = 2,
	TEXTURE_RGB = 3,
	TEXTURE_RGBA = 4
};

class ImageLoader {
public:
	static ImageLoader& getInstance();
	ImageLoader();
	~ImageLoader();
	unsigned char* Load(char* path, int width, int height, int format);
};

ImageLoader::ImageLoader() {

}

ImageLoader::~ImageLoader() {

}

ImageLoader& ImageLoader::getInstance()
{
	static ImageLoader instance;
	return instance;
}

unsigned char* ImageLoader::Load(char* path, int width, int height, int format) {
	return SOIL_load_image(path, &width, &height, 0, SOIL_LOAD_RGB);

}