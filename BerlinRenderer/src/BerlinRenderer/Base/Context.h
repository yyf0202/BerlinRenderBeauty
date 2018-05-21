//0.1.1
//���δ��� (2018.05.09)
//
// �޸ļ�¼
///////////////////////////////////////////////////////////////////

#ifndef _CONTEXT_H
#define _CONTEXT_H
#pragma once
#include <BerlinRenderer\Base\PreDeclare.h>
#include <BerlinRenderer\Render\RenderEngine.h>
#include <BerlinRenderer\Resources\ResourceManager.h>
#include <BerlinRenderer\Scene Manager\SceneManager.h>
#include <BerlinRenderer\App\App.h>
#include <BerlinRenderer\Base\Utils.h>

namespace BRE {
	class Context : boost::noncopyable
	{
	public:
		Context();
		~Context();

		static Context& Instance();
		static void Destroy();
		void Suspend();
		void Resume();
		void DestroyAll();
		void AppInstance(App& app);

		RenderEngine& RenderEngineInstance();
		ResourceManager& ResourceManagerInstance();
		SceneManager& SceneManagerInstance();

	private:
	
		static std::unique_ptr<Context> context_instance_;

		App* app_;
		std::unique_ptr<RenderEngine> render_engine_instance_;
		std::unique_ptr<ResourceManager> resource_manager_;
		std::unique_ptr<SceneManager> scene_manager_instance_;
	};
}
#endif
