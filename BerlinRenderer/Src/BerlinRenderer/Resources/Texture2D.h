#pragma once

#include <BerlinRenderer/Base/Config.h>
#include "Resource.h"

NS_RENDER_BEGIN

class RENDER_API Texture2D : Resource
{
public:
	Texture2D();

	virtual void Load(string_t name) override;

	void SetData(byte_t* data, uint32_t of_x, uint32_t of_y, uint32_t width, uint32_t height);
	void UpdateParameters();

	void SetSize(uint32_t width, uint32_t height);
	inline uint32_t GetWidth() const { return width_; }
	inline uint32_t GetHeight() const { return height_; }

	error_t Bind();

	// TODO:
	uint32_t GetFormat() const { return 0; }
	void SetFormat(uint32_t format) { format_ = format; }

	uint32_t GetDataType() const { return dataType_; }
	void SetDataType(uint32_t type) { dataType_ = type; }
	GLuint GetGPUOjbectId() const { return id_; }

protected:
	GLuint id_;

private:
	error_t Init();

protected:
	uint32_t	width_ = 0;
	uint32_t	height_ = 0;
	bool_t		paramDirty_ = true;
	uint32_t	format_ = GL_RGB;
	uint32_t	dataType_ = GL_UNSIGNED_BYTE;
};

NS_RENDER_END