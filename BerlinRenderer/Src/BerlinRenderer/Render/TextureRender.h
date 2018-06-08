#pragma once

#include "Renderer.h"

NS_RENDER_BEGIN

class Texture2D;

class RENDER_API TextureRender : public Renderer
{
public:
	//void Render() override;

	void SetTexture(Texture2D* tex);
	Texture2D* GetTexture() const { return tex_; }

private:
	Texture2D* tex_;
};

NS_RENDER_END