// 0.1.1
// ���δ��� (2018.05.09)
//
// �޸ļ�¼
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