#pragma once

#include <BerlinRenderer/Base/Config.h>
#include <BerlinRenderer/Render/Renderer.h>

NS_RENDER_BEGIN

class RectRender : public Renderer
{
public:
	RectRender();

	virtual void Draw(Camera* camera) override;

private:
	GLuint vao_ = 0;
	GLuint vbo_ = 0;
	GLuint ebo_ = 0;
};


NS_RENDER_END