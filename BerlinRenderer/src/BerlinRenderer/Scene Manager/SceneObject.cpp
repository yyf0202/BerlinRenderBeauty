//0.1.1
//初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#include "SceneObject.h"
#include <BerlinRenderer/Base/Context.h>
#include <BerlinRenderer/Scene Manager/SceneManager.h>
//#include <BerlinRenderer/Render/Renderer.h>
#include <BerlinRenderer/Profiler/Profiler.h>

NS_RENDER_BEGIN

SceneObject::SceneObject()
{
	local_matrix_ = mat4_t(1.0f);
	abs_matrix_ = mat4_t(1.0f);
	//renderer_ = new Renderer(this);
}

SceneObject::~SceneObject()
{

}

void SceneObject::AddToSceneManager()
{
	Context::GetInstance().SceneManagerInstance().AddSceneObject(this->shared_from_this());

	for (auto const & child : children_)
	{
		child->AddToSceneManager();
	}
}

void SceneObject::DelFromSceneManager()
{
	for (auto const & child : children_)
	{
		child->DelFromSceneManager();
	}

	Context::GetInstance().SceneManagerInstance().DelSceneObject(this->shared_from_this());
}

void SceneObject::UpdateWorldMatrix()
{
	PROFILE_FUNCTION();

	if (parent_) {
		abs_matrix_ = parent_->GetLocalMatrix() * local_matrix_;
	}
	else {
		abs_matrix_ = local_matrix_;
	}
}

void SceneObject::Update() {
	PROFILE_FUNCTION();

	UpdateWorldMatrix();
}

//RenderablePtr const & SceneObject::GetRenderable() const
//{
//	return this->renderable_;
//}

NS_RENDER_END