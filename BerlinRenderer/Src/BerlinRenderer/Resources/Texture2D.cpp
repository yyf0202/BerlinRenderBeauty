
#include "Texture2D.h"
#include "ResourceManager.h"
#include <BerlinRenderer/Base/Context.h>
#include <BerlinRenderer/IO/LoggerManager.h>
#include "Image.h"

NS_RENDER_BEGIN

Texture2D::Texture2D()
{
	Init();
}

void Texture2D::Load(string_t name)
{
	auto img = Context::GetInstance().ResourceManagerInstance().Load<Image>(name);

	// TODO: error
	if (img == nullptr) return;

	//glActiveTexture(GL_TEXTURE0);

	Bind();
	UpdateParameters();
	SetData(img->GetData(), 0, 0, img->GetWidth(), img->GetHeight());
	glBindTexture(GL_TEXTURE_2D, 0);
	CHECK_OPENGL();

	return;
}

error_t Texture2D::Bind()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, id_);

	return 0;
}

void Texture2D::SetData(byte_t* data, uint32_t of_x, uint32_t of_y, uint32_t width, uint32_t height)
{
	glTexImage2D(GL_TEXTURE_2D, 0, GetFormat(), (GLsizei)width, (GLsizei)height, 0, GetFormat()/* TODO */, GL_UNSIGNED_BYTE/* TODO */, data);
}

void Texture2D::SetSize(uint32_t width, uint32_t height)
{
	width_ = width;
	height_ = height;
}

void Texture2D::UpdateParameters()
{
	if (!paramDirty_) return;

	// TODO support config
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	paramDirty_ = false;
}

error_t Texture2D::Init()
{
	if (id_ == 0)
	{
		glGenTextures(1, &id_);
	}

	return 0;
}

NS_RENDER_END