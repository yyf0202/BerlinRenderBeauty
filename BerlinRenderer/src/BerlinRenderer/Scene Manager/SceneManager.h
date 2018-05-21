// 0.1.1
// ���δ��� (2018.05.09)
//
// �޸ļ�¼
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

		void AddCamera(CameraPtr const & camera);
		void DelCamera(CameraPtr const & camera);

		void Update();

	private:
		std::vector<SceneObjectPtr> scene_objs_;
		std::vector<CameraPtr> cameras_;
	};
}
#endif