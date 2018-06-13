#pragma once
#pragma once

#include <BerlinRenderer/Base/Config.h>
#include <BerlinRenderer/Render/Renderer.h>

NS_RENDER_BEGIN

class MeshRender: public Renderer
{
public:

	virtual void Draw() override;
};

NS_RENDER_END