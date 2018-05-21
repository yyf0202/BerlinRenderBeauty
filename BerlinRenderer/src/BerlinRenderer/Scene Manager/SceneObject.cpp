//0.1.1
//初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#include "SceneObject.h"
#include <BerlinRenderer/Base/Context.h>

NS_RENDER_BEGIN

SceneObject::SceneObject()
{
	local_matrix_ = mat4_t(1.0f);
	abs_matrix_ = mat4_t(1.0f);
}

SceneObject::~SceneObject()
{

}

void SceneObject::AddToSceneManager()
{
	Context::Instance().SceneManagerInstance().AddSceneObject(this->shared_from_this());

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

	Context::Instance().SceneManagerInstance().DelSceneObject(this->shared_from_this());
}

void SceneObject::UpdateWorldMatrix()
{
	if (parent_) {
		abs_matrix_ = parent_->GetLocalMatrix() * local_matrix_;
	}
	else {
		abs_matrix_ = local_matrix_;
	}
}

//RenderablePtr const & SceneObject::GetRenderable() const
//{
//	return this->renderable_;
//}

NS_RENDER_END