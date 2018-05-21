//0.1.1
//初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#include "SceneObject.h"

namespace BRE {
	SceneObject::SceneObject()
	{
		local_matrix_ = glm::mat4(1.0f);
		abs_matrix_ = glm::mat4(1.0f);
	}

	SceneObject::~SceneObject() {

	}

	void SceneObject::AddToSceneManager() {
		Context::Instance().SceneManagerInstance().AddSceneObject(this->shared_from_this());

		for (auto const & child : children_)
		{
			child->AddToSceneManager();
		}
	}

	void SceneObject::DelFromSceneManager() {
		for (auto const & child : children_)
		{
			child->DelFromSceneManager();
		}

		Context::Instance().SceneManagerInstance().DelSceneObject(this->shared_from_this());
	}

	void SceneObject::UpdateWorldMatrix() {
		if (parent_) {
			abs_matrix_ = parent_->GetLocalMatrix() * local_matrix_;
		}
		else {
			abs_matrix_ = local_matrix_;
		}
	}

	void SceneObject::LocalMatrix(glm::mat4 const& localMatrix) {
		this->local_matrix_ = localMatrix;
	}

	const glm::mat4& SceneObject::GetLocalMatrix() const {
		return this->local_matrix_;
	}

	void SceneObject::WorldMatrix(glm::mat4 const& worldMatrix) {
		this->abs_matrix_ = worldMatrix;
	}

	const glm::mat4& SceneObject::GetWorldMatrix() const {
		return this->abs_matrix_;
	}

	void SceneObject::ObjectID(uint32_t id) {
		this->object_id_ = id;
	}

	SceneObject* SceneObject::Parent() const {
		return this->parent_;
	}


	void SceneObject::Parent(SceneObject* so)
	{
		this->parent_ = so;
	}

	uint32_t SceneObject::NumChildren() const {
		return this->children_.size();
	}

	const SceneObjectPtr& SceneObject::Child(uint32_t index) const
	{
		return this->children_[index];
	}

	RenderablePtr const & SceneObject::GetRenderable() const {
		return this->renderable_;
	}

	Mesh const & SceneObject::GetMeshData() const {
		return this->mesh_data;
	}
}