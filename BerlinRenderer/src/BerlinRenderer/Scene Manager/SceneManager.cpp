//0.1.1
//初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////
#include "SceneManager.h"
#include <BerlinRenderer/Profiler/Profiler.h>
#include <BerlinRenderer/Action/IActionManager.h>

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

void SceneManager::Update()
{
	PROFILE_FUNCTION();
	for_each(iter, cameras_)
	{
		(*iter)->GetActionManager().OnUpdate();
	}

	for (auto iter = scene_objs_.begin(); iter != scene_objs_.end(); ++iter)
	{
		(*iter)->Update();
	}
}

void SceneManager::AddCamera(Camera* camera)
{
	cameras_.push_back(camera);
}

void SceneManager::DelCamera(Camera* camera)
{
	auto iter = std::find(cameras_.begin(), cameras_.end(), camera);
	cameras_.erase(iter);
}

const Camera& SceneManager::ActiveCamera()
{
	return *cameras_[0];
}

NS_RENDER_END