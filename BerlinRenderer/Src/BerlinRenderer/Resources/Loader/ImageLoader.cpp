
#include "ImageLoader.h"

NS_RENDER_BEGIN

ImageLoader::~ImageLoader()
{

}

shared_ptr_t<Image> ImageLoader::Load(string_t path)
{
	auto fd = images_.find(path);
	if (fd != images_.end()) return fd->second;

	int width, height;

	byte_t* data = nullptr;
	/*data = SOIL_load_image(path.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
	if (data == nullptr) return shared_ptr_t<Image>(nullptr);*/

	auto img = new Image();
	img->SetData(data);
	images_[path] = shared_ptr_t<Image>(img);

	return shared_ptr_t<Image>(img);
}

NS_RENDER_END