#pragma once
#include <soil.h>

enum
{
	TEXTURE_AUTO = 0,
	TEXTURE_L = 1,
	TEXTURE_LA = 2,
	TEXTURE_RGB = 3,
	TEXTURE_RGBA = 4
};

#include <BerlinRenderer/Base/Config.h>

NS_RENDER_BEGIN

class Texture2D;

class ImageLoader
{
public:
	static ImageLoader& getInstance();
	ImageLoader();
	~ImageLoader();
	Texture2D* Load(string_t path, int32_t width, int32_t height, int32_t format);
};

NS_RENDER_END