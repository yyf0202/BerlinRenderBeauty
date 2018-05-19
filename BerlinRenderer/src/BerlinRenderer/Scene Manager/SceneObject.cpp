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

	}

	void SceneObject::DelFromSceneManager() {

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


	void SetPosition();
	glm::vec3 GetPosition;
}