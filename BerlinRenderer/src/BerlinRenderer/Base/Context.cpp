//0.1.1 
//初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#include <BerlinRenderer/Base/Utils.h>
#include <BerlinRenderer/Base/Context.h>
#include <BerlinRenderer/Scene Manager/SceneManager.h>
#include <BerlinRenderer/Resources/ResourceManager.h>
#include <BerlinRenderer/Render/RenderEngine.h>
#include <BerlinRenderer/Task/TaskManager.h>
#include <BerlinRenderer/Task/ThreadPool.h>

NS_RENDER_BEGIN

Context::Context()
{
	if (!scene_manager_instance_)
		scene_manager_instance_ = new SceneManager();

	if (!resource_manager_)
	{
		resource_manager_ = new ResourceManager();
		resource_manager_->Init();
	}

	if (!render_engine_instance_)
		render_engine_instance_ = new RenderEngine();

	if (task_manager_instance_ == nullptr)
	{
		task_manager_instance_ = new TaskManager(new ThreadPool(std::thread::hardware_concurrency() * 2));
	}
}

Context::~Context()
{

}

void Context::Suspend()
{

}

void Context::Resume()
{

}

void Context::DestroyAll()
{
	//if (scene_manager_instance_)
	//	scene_manager_instance_->reset();

	//if (resource_manager_)
	//	resource_manager_.reset();

	//if (render_engine_instance_)
	//	render_engine_instance_.reset();
}

void Context::Destroy()
{
	//if (!context_instance_)
	//{
	//	context_instance_->DestroyAll();
	//	context_instance_.reset();
	//}
}

void Context::AppInstance(App& app)
{
	app_ = &app;
}

RenderEngine& Context::RenderEngineInstance()
{
	return *render_engine_instance_;
}

ResourceManager& Context::ResourceManagerInstance()
{
	return *resource_manager_;
}

SceneManager& Context::SceneManagerInstance()
{
	return *scene_manager_instance_;
}

TaskManager& Context::TaskManagerInstance()
{
	return *task_manager_instance_;
}

NS_RENDER_END