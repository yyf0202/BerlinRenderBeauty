// 0.1.1
// 初次创建 (2018.05.10)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#include "RenderEngine.h"

NS_RENDER_BEGIN

RenderEngine::RenderEngine()
{

}

RenderEngine::~RenderEngine()
{

}

void RenderEngine::Refresh()
{
	SceneManager& sm = Context::GetInstance().SceneManagerInstance();

	//update scene object local matrix
	//sm.Update();

	//for (auto iter = sm.GetSceneObjects().begin(); iter != sm.GetSceneObjects().end(); ++iter)
	//{
	//	//SceneObject* ptr = iter->_Get();

	//	//if (ptr->GetRenderer()) {
	//	//	ptr->GetRenderer()->Draw();
	//	//}
	//}
}

NS_RENDER_END