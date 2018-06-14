//0.1.1
//初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#pragma once

#include <BerlinRenderer/Base/Config.h>
#include <BerlinRenderer/Base/Singleton.h>

NS_RENDER_BEGIN

class App;
class RenderEngine;
class ResourceManager;
class SceneManager;
class TaskManager;
class LoggerManager;

class Context : Noncopyable, public Singleton<Context>
{
public:
	Context();
	~Context();

	static void Destroy();
	void Suspend();
	void Resume();
	void DestroyAll();
	void AppInstance(App& app);

	RenderEngine& RenderEngineInstance();
	ResourceManager& ResourceManagerInstance();
	SceneManager& SceneManagerInstance();
	TaskManager& TaskManagerInstance();
	LoggerManager& LoggerManagerInstance() { return *logger_manager_instance_; }

	void Init();

	bool_t IsMainThread();

private:

	App* app_ = nullptr;
	RenderEngine* render_engine_instance_ = nullptr;
	ResourceManager* resource_manager_ = nullptr;
	SceneManager* scene_manager_instance_ = nullptr;
	TaskManager* task_manager_instance_ = nullptr;
	LoggerManager* logger_manager_instance_ = nullptr;

	std::thread::id mainThreadId_;
};

NS_RENDER_END