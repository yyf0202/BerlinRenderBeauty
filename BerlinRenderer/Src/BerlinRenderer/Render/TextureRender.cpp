
#include "TextureRender.h"
#include <BerlinRenderer/Resources/Texture2D.h>
#include <BerlinRenderer/Resources/Material/Material.h>

NS_RENDER_BEGIN

void TextureRender::Draw()
{
	if (tex_ == nullptr) return;
	if (mat_ == nullptr) return; // add a default materail?

	glActiveTexture(GL_TEXTURE0);

	//mat_->SetMat4(MODEL_MATRIX, object_->GetWorldMatrix());
	//mat_->SetMat4(VIEW_MATRIX, camera->GetViewMatrix());
	//mat_->SetMat4(PROJECTION_MATRIX, camera->GetProjectionMatrix());

	tex_->Bind();
	mat_->Use();


}

void TextureRender::SetTexture(Texture2D* tex)
{
	tex_ = tex;
}

NS_RENDER_END