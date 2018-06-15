// 0.1.1
// 初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#include "App.h"

#include <BerlinRenderer/Render/RenderEngine.h>
#include <BerlinRenderer/Base/Context.h>
#include <BerlinRenderer/Profiler/Profiler.h>
#include <BerlinRenderer/Base/Timer.h>
#include <BerlinRenderer/Task/TaskManager.h>
#include <BerlinRenderer/IO/LoggerManager.h>
#include <BerlinRenderer/Resources/ResourceManager.h>

NS_RENDER_BEGIN

static void Log(string_t& msg)
{
	printf(msg.c_str());
}

App::App(string_t const & name)
	: name_(name)
	, window_width(400)
	, window_height(400)
{
}

App::~App()
{
}

bool_t App::Init()
{
	glfwInit();

	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	glWindow_ = glfwCreateWindow(window_width, window_height, name_.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(glWindow_);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		LOG_ERROR("Failed to initialize GLAD");
		return false;
	}

	glViewport(0, 0, window_width, window_height);

	frameTime_ = 1000 / FPS_;

	bool_t ret = true;

	ret |= Context::GetInstance().Init();
	if (!ret) return ret;

	Context::GetInstance().SetAppInstance(this);

	ret |= Context::GetInstance().ResourceManagerInstance().Init();
	if (!ret) return ret;

	ret |= Context::GetInstance().LoggerManagerInstance().Init("./info.log");
	if (!ret) return ret;

	Context::GetInstance().LoggerManagerInstance().SetLogCallback(Log);

	return ret;
}

void App::Key_Callback(GLFWwindow* window, int32_t key, int32_t scancode, int32_t action, int32_t mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

void App::Destroy()
{
}

void App::Suspend()
{
}

void App::Resume()
{
}

void App::Refresh()
{
}

bool_t App::Startup()
{
	return true;
}

void App::Run()
{
	if (!Init())
	{
		LOG_ERROR("app init error");
		return;
	}

	if (!Startup())
	{
		LOG_ERROR("app startup error");
		return;
	}

	auto& renderMgr = Context::GetInstance().RenderEngineInstance();
	auto& taskMgr = Context::GetInstance().TaskManagerInstance();
	auto& loggerMgr = Context::GetInstance().LoggerManagerInstance();

	Timer timer;

	while (!glfwWindowShouldClose(glWindow_))
	{
		timer.Begin();

		if (!suspend_)
		{
			CpuRegion _region("App::Run");

			++frames_;

			// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
			glfwPollEvents();

			taskMgr.Update();

			// Render
			// Clear the colorbuffer
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			renderMgr.Refresh();

			glfwSwapBuffers(glWindow_);

			loggerMgr.Update();
		}

		timer.End();

		auto milli = timer.Milliseconds();
		if (milli >= frameTime_)
		{
			deltaTime_ = milli;
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(frameTime_ - milli));
			deltaTime_ = frameTime_;
		}
	}

	glfwTerminate();
}

void App::Quit()
{

}

NS_RENDER_END