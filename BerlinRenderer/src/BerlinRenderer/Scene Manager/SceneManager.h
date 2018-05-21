// 0.1.1
// 初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#ifndef _SCENEMANAGER_H
#define _SCENEMANAGER_H
#pragma once
#include <BerlinRenderer\Base\PreDeclare.h>
#include <vector>

namespace BRE {
	class SceneManager : boost::noncopyable
	{
	public:
		SceneManager();
		virtual ~SceneManager();

		void AddSceneObject(SceneObjectPtr const & obj);
		void DelSceneObject(SceneObjectPtr const & obj);

		void Update();

	private:
		std::vector<SceneObjectPtr> scene_objs_;
	};
}
#endif