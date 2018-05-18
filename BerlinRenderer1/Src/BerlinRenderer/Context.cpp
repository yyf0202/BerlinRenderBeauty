//0.1.1 
//初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#include "Context.h"
#include "Utils.h"
#include <memory>

namespace BRE {
	Context::Context() {
		if (!scene_manager_instance_)
			scene_manager_instance_ = MakeUniquePtr<SceneManager>();

		if (!resource_manager_)
			resource_manager_ = MakeUniquePtr<ResourceManager>();

		if (!render_engine_instance_)
			render_engine_instance_ = MakeUniquePtr<RenderEngine>();
	}

	Context::~Context() {

	}

	void Context::Suspend() {

	}

	//void Context::Suspend() {

	//}

	void Context::Resume() {

	}

	void Context::DestroyAll() {
		if (scene_manager_instance_)
			scene_manager_instance_.reset();

		if (resource_manager_)
			resource_manager_.reset();

		if (render_engine_instance_)
			render_engine_instance_.reset();
	}

	void Context::Destroy() {
		if (!context_instance_)
		{
			context_instance_->DestroyAll();
			context_instance_.reset();
		}
	}

	Context& Context::Instance() {
		if (!context_instance_) {
			context_instance_ = MakeUniquePtr<Context>();
		}

		return *context_instance_;
	}

	void Context::AppInstance(App& app)
	{
		app_ = &app;
	}

	RenderEngine& Context::RenderEngineInstance()
	{
		if (!render_engine_instance_)
		{
			render_engine_instance_ = MakeUniquePtr<RenderEngine>();
		}

		return *render_engine_instance_;
	}

	ResourceManager& Context::ResourceManagerInstance() {
		if (!resource_manager_)
		{
			resource_manager_ = MakeUniquePtr<ResourceManager>();
		}

		return *resource_manager_;
	}

	SceneManager& Context::SceneManagerInstance() {
		if (!scene_manager_instance_)
		{
			scene_manager_instance_ = MakeUniquePtr<SceneManager>();
		}

		return *scene_manager_instance_;
	}

}