#pragma once

#include <BerlinRenderer/Base/Config.h>
#include <BerlinRenderer/Render/Renderer.h>

NS_RENDER_BEGIN

class RectRender : public Renderer
{
public:
	virtual void Draw() override;
};


NS_RENDER_END