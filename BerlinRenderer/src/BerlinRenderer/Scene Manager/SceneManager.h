// 0.1.1
// 初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////
#pragma once

#include <BerlinRenderer\Base\Config.h>
#include "SceneObject.h"

NS_RENDER_BEGIN

class RENDER_API SceneManager : Noncopyable
{
public:
	SceneManager();
	virtual ~SceneManager();

	void AddSceneObject(SceneObjectPtr const & obj);
	void DelSceneObject(SceneObjectPtr const & obj);

	void Update();

private:
	vector_t<SceneObjectPtr> scene_objs_;
};

NS_RENDER_END