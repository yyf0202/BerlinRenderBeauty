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

#define ResourceMgr()	RENDER Context::GetInstance().ResourceManagerInstance()
#define SceneMgr()		RENDER Context::GetInstance().SceneManagerInstance()
#define RenderMgr()		RENDER Context::GetInstance().RenderEngineInstance()
#define TaskMgr()		RENDER Context::GetInstance().TaskManagerInstance()
#define LoggerMgr()		RENDER Context::GetInstance().LoggerManagerInstance()

class Context : Noncopyable, public Singleton<Context>
{
public:
	Context();
	~Context();

	bool_t Init();
	void Suspend();
	void Resume();
	void DestroyAll();
	static void Destroy();

	inline void AppInstance(App& app) { app_ = &app; }
	inline RenderEngine& RenderEngineInstance() { return *render_engine_instance_;	}
	inline ResourceManager& ResourceManagerInstance() { return *resource_manager_;	}
	inline SceneManager& SceneManagerInstance() { return *scene_manager_instance_;	}
	inline TaskManager& TaskManagerInstance() { return *task_manager_instance_; }
	inline LoggerManager& LoggerManagerInstance() { return *logger_manager_instance_; }
	inline bool_t IsMainThread() { return mainThreadId_ == std::this_thread::get_id(); }

	inline float_t GetDeltaTime() { return deltaTime_; }

protected:
	void SetAppInstance(App* app) { app_ = app; }
	inline void SetDeltaTime(float_t value) { deltaTime_ = value; }

private:

	App* app_ = nullptr;
	RenderEngine* render_engine_instance_ = nullptr;
	ResourceManager* resource_manager_ = nullptr;
	SceneManager* scene_manager_instance_ = nullptr;
	TaskManager* task_manager_instance_ = nullptr;
	LoggerManager* logger_manager_instance_ = nullptr;

	std::thread::id mainThreadId_;
	float_t deltaTime_ = 0;

	friend App;
};

NS_RENDER_END