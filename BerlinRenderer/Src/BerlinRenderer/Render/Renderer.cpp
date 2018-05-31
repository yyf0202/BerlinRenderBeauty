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
	if (object_ == NULL) {
		return;
	}

	shader_->Use();

	//Set MVP Matrix
	SceneManager sceneManager;
	CameraPtr camera = sceneManager.ActiveCamera();
	shader_->SetMat4(MODEL_MATRIX, object_->GetWorldMatrix());
	shader_->SetMat4(VIEW_MATRIX, camera->GetViewMatrix());
	shader_->SetMat4(PROJECTION_MATRIX, camera->GetProjectionMatrix());
	shader_->SetInt(DIFFUSE_TEXTURE, object_->GetMeshData().GetDiffuseTexture());
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, object_->GetMeshData().GetDiffuseTexture());



	glBindVertexArray(object_->GetMeshData().GetVertexArray());
	glDrawElements(GL_TRIANGLES, this->object_->GetMeshData().indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);


	glActiveTexture(GL_TEXTURE0);
}

NS_RENDER_END