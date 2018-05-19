//0.1.1
//初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#ifndef _CONTEXT_H
#define _CONTEXT_H
#pragma once
#include "PreDeclare.h"
#include "RenderEngine.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "App.h"

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
