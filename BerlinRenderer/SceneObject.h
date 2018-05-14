//0.1.1
//初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////
#ifndef _SCENEOBJECT_H
#define _SCENEOBJECT_H
#pragma once
#include "PreDeclare.h"
#include <vector>
#include "Mesh.h"

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
	protected:
		SceneObject* parent_;
		std::vector<SceneObjectPtr> children_;
		RenderablePtr renderable_;
		Mesh mesh_data;
	};

}
#endif