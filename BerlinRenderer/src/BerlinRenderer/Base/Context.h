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

private:

	App* app_ = nullptr;
	RenderEngine* render_engine_instance_ = nullptr;
	ResourceManager* resource_manager_ = nullptr;
	SceneManager* scene_manager_instance_ = nullptr;
};

NS_RENDER_END