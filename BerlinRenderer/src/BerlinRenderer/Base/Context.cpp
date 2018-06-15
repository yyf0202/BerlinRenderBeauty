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
#include <BerlinRenderer/IO/LoggerManager.h>

NS_RENDER_BEGIN

Context::Context()
{
	scene_manager_instance_ = new SceneManager();
	resource_manager_ = new ResourceManager();
	render_engine_instance_ = new RenderEngine();
	task_manager_instance_ = new TaskManager(new ThreadPool(std::thread::hardware_concurrency() * 2));
	logger_manager_instance_ = new LoggerManager();
}

Context::~Context()
{
}

bool_t Context::Init()
{
	mainThreadId_ = std::this_thread::get_id();

	return true;
}

void Context::Suspend()
{
}

void Context::Resume()
{
}

void Context::DestroyAll()
{
}

void Context::Destroy()
{
}


NS_RENDER_END