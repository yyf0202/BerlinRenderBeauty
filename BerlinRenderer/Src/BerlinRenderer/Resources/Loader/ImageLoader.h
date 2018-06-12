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
#include "Loader.h"

NS_RENDER_BEGIN

class Image;

class ImageLoader : public Loader<Image>
{
public:
	ImageLoader(string_t path, function_t<void(Image*)> loaded) : Loader(path, loaded) {}

	static Image* Load(string_t path);

	virtual void BeginTask() override;
	virtual void EndTask() override;
};

NS_RENDER_END