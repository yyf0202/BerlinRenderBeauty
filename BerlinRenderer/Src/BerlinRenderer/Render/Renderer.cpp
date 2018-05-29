// 0.1.1 
// 初次创建 (2018.05.10)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#include "Renderer.h"

NS_RENDER_BEGIN

Renderer::Renderer(SceneObject* sceneObject) {
	if (!sceneObject)
		return;

	object_ = sceneObject;
	shader_ = new Shader();
}


Renderer::~Renderer()
{

}

void Renderer::Draw()
{
	if (object_ ==NULL) {
		return;
	}

	shader_->Use();

	//Set MVP Matrix
	SceneManager sceneManager;
	CameraPtr camera = sceneManager.ActiveCamera();
	shader_->SetMat4(MODEL_MATRIX, object_->GetWorldMatrix());
	shader_->SetMat4(VIEW_MATRIX, camera->GetViewMatrix());
	shader_->SetMat4(PROJECTION_MATRIX, camera->GetProjectionMatrix());

	glActiveTexture(GL_TEXTURE0);
	shader_->SetInt(DIFFUSE_TEXTURE, 0);
	glBindTexture(GL_TEXTURE_2D, object_->GetMeshData().GetDiffuseTexture());

	glBindVertexArray(object_->GetMeshData().);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	// always good practice to set everything back to defaults once configured.
	glActiveTexture(GL_TEXTURE0);
}

NS_RENDER_END