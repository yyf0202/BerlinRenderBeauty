#pragma once

#include "Renderer.h"

NS_RENDER_BEGIN

class Texture2D;

class RENDER_API TextureRender : public Renderer
{
public:
	TextureRender();
	void Draw() override;

	void SetTexture(Texture2D* tex);
	Texture2D* GetTexture() const { return tex_; }

private:
	Texture2D* tex_;
	GLuint vao_ = 0;
	GLuint vbo_ = 0;
	GLuint ebo_ = 0;
};

NS_RENDER_END