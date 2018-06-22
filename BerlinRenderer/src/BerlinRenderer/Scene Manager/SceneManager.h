// 0.1.1
// 初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////
#pragma once

#include <BerlinRenderer/Base/Config.h>
#include "SceneObject.h"
#include <BerlinRenderer/Render/Camera.h>
#include <BerlinRenderer/Scene Manager/SceneObject.h>

NS_RENDER_BEGIN

class RENDER_API SceneManager : Noncopyable
{
public:
	SceneManager();
	virtual ~SceneManager();

	void AddSceneObject(SceneObjectPtr const & obj);
	void DelSceneObject(SceneObjectPtr const & obj);

	void Update();


	void AddCamera(Camera* camera);
	void DelCamera(Camera* camera);

	const Camera& ActiveCamera();

	const vector_t<SceneObjectPtr>& GetSceneObjects() { return scene_objs_;	}
	const vector_t<Camera*> GetCameras() { return cameras_; }

private:
	vector_t<SceneObjectPtr> scene_objs_;
	vector_t<Camera* > cameras_;
};

NS_RENDER_END

