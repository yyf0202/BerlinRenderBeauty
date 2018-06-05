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
#include <BerlinRenderer/base/Singleton.h>
#include "../Image.h"

NS_RENDER_BEGIN

class ImageLoader : public Singleton<ImageLoader>
{
public:
	~ImageLoader();
	shared_ptr_t<Image> Load(string_t path);

private:
	hash_t<string_t, shared_ptr_t<Image>> images_;
};

NS_RENDER_END