//0.1.1
//初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////
#ifndef _SCENEOBJECT_H
#define _SCENEOBJECT_H
#pragma once
#include <BerlinRenderer\Base\PreDeclare.h>
#include <BerlinRenderer\Base\Context.h>
#include <BerlinRenderer\Render\mesh.h>
#include <vector>

namespace BRE {

	class SceneObject : boost::noncopyable, public std::enable_shared_from_this<SceneObject>
	{
	public:
		SceneObject();
		~SceneObject();

		void AddToSceneManager();
		void DelFromSceneManager();

		void ObjectID(uint32_t id);

		SceneObject* Parent() const;
		void Parent(SceneObject* so);
		uint32_t NumChildren() const;
		const SceneObjectPtr& Child(uint32_t index) const;

		RenderablePtr const & GetRenderable() const;
		Mesh const & GetMeshData() const;

		void LocalMatrix(glm::mat4 const& localMatrix);
		const glm::mat4& GetLocalMatrix() const;

		void WorldMatrix(glm::mat4 const& worldMatrix);
		const glm::mat4& GetWorldMatrix() const;
		void UpdateWorldMatrix();
	protected:
		SceneObject* parent_;
		std::vector<SceneObjectPtr> children_;
		RenderablePtr renderable_;
		Mesh mesh_data;
		uint32_t object_id_;
		glm::mat4 local_matrix_;
		glm::mat4 abs_matrix_;
	};

}
#endif