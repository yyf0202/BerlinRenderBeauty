//0.1.1
//初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////
#pragma once

#include <BerlinRenderer/Base/Config.h>
#include <BerlinRenderer/Base/Noncopyable.h>
#include <BerlinRenderer/Resources/Mesh.h>

NS_RENDER_BEGIN

class Renderer;
class IActionManager;

class SceneObject : Noncopyable, public std::enable_shared_from_this<SceneObject>
{
public:
	SceneObject();
	~SceneObject();

	void AddToSceneManager();
	void DelFromSceneManager();

	void SetPosition(vec3_t& pos);
	const vec3_t& GetPostion() { return pos_; }

	inline void SetObjectID(uint32_t id) { object_id_ = id; }

	inline SceneObject* Parent() const { return parent_; }
	inline void SetParent(SceneObject* so) { parent_ = so; }
	inline size_t NumChildren() const { return children_.size(); }
	inline const shared_ptr_t<SceneObject> & Child(uint32_t index) const { return children_[index]; }

	//RenderablePtr const & GetRenderable() const;
	//inline Mesh const & GetMeshData() const { return mesh_data_; }

	inline void SetLocalMatrix(mat4_t const& localMatrix) { local_matrix_ = localMatrix; }
	inline const mat4_t& GetLocalMatrix() const { return local_matrix_; }

	inline void SetWorldMatrix(mat4_t const& worldMatrix) { abs_matrix_ = worldMatrix; }
	inline const mat4_t& GetWorldMatrix() const { return abs_matrix_; }

	void Update();

	inline Renderer* GetRenderer() { return renderer_;	}
	void SetRender(Renderer* renderer);
	//inline void Set(Mesh mesh) { mesh_data_ = mesh; }
	inline IActionManager& GetActionManager() { return *actionManager_; }

protected:
	SceneObject * parent_;
	vector_t<shared_ptr_t<SceneObject>> children_;
	//RenderablePtr renderable_;
	//Mesh mesh_data_;
	uint32_t object_id_ = 0;
	mat4_t local_matrix_;
	mat4_t abs_matrix_;
	void UpdateWorldMatrix();
	Renderer* renderer_ = nullptr;
	vec3_t pos_;
	bool_t dirtyLocalMat_ = false;
	IActionManager* actionManager_ = nullptr;
};

typedef shared_ptr_t<SceneObject> SceneObjectPtr;

NS_RENDER_END