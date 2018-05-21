//0.1.1
//初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////
#include <BerlinRenderer\Scene Manager\SceneManager.h>

namespace BRE {
	SceneManager::SceneManager() {

	}

	SceneManager::~SceneManager() {

	}


	void SceneManager::AddSceneObject(SceneObjectPtr const & obj) {
		scene_objs_.push_back(obj);
	}

	void SceneManager::DelSceneObject(SceneObjectPtr const & obj) {
		for (auto iter = scene_objs_.begin(); iter != scene_objs_.end(); ++iter)
		{
			if (*iter == obj)
			{
				scene_objs_.erase(iter);
				break;
			}
		}
	}

	void SceneManager::AddCamera(CameraPtr const & camera) {
		cameras_.push_back(camera);
	}
	void SceneManager::DelCamera(CameraPtr const & camera) {
		auto iter = std::find(cameras_.begin(), cameras_.end(), camera);
		cameras_.erase(iter);
	}

	void SceneManager::Update() {
		for (auto iter = scene_objs_.begin(); iter != scene_objs_.end(); ++iter)
		{
		
		}
	}
}