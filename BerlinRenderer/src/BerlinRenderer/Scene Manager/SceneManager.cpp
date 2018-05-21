//0.1.1
//初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////
#include "SceneManager.h"

NS_RENDER_BEGIN

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{

}

void SceneManager::AddSceneObject(SceneObjectPtr const & obj)
{
	scene_objs_.push_back(obj);
}

void SceneManager::DelSceneObject(SceneObjectPtr const & obj)
{
	for (auto iter = scene_objs_.begin(); iter != scene_objs_.end(); ++iter)
	{
		if (*iter == obj)
		{
			scene_objs_.erase(iter);
			break;
		}
	}
}

void SceneManager::Update() {

}

NS_RENDER_END