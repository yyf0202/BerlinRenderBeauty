//0.1.1
//初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#pragma once

#include <BerlinRenderer/Base/Config.h>
#include <BerlinRenderer/App/App.h>
#include <BerlinRenderer/Render/RenderEngine.h>
#include <BerlinRenderer/Resources/ResourceManager.h>
#include <BerlinRenderer/Scene Manager/SceneManager.h>

NS_RENDER_BEGIN

class Context : Noncopyable
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

	static unique_ptr_t<Context> context_instance_;

	App* app_;
	unique_ptr_t<RenderEngine> render_engine_instance_;
	unique_ptr_t<ResourceManager> resource_manager_;
	unique_ptr_t<SceneManager> scene_manager_instance_;
};

NS_RENDER_END