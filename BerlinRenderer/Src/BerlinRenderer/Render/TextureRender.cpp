
#include "TextureRender.h"
#include <BerlinRenderer/Resources/Texture2D.h>
#include <BerlinRenderer/Resources/Material/Material.h>

NS_RENDER_BEGIN

//void TextureRender::Render()
//{
//	if (tex_ == nullptr) return;
//	if (mat_ == nullptr) return; // add a default materail?
//
//	glActiveTexture(GL_TEXTURE0);
//	tex_->Bind();
//	mat_->Use();
//
//}

void TextureRender::SetTexture(Texture2D* tex)
{
	tex_ = tex;
}

NS_RENDER_END