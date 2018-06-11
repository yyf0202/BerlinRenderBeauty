// 0.1.1
// 初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#include "App.h"

#include <BerlinRenderer/Render/RenderEngine.h>
#include <BerlinRenderer/Base/Context.h>
#include <BerlinRenderer/Resources/Loader/ShaderLoader.h>
#include <BerlinRenderer/Profiler/Profiler.h>
#include <BerlinRenderer/Base/Timer.h>

NS_RENDER_BEGIN

App::App(string_t const & name)
	: name_(name)
	, window_width(400)
	, window_height(400)
{
}

App::~App()
{
}

void App::Create()
{
	glfwInit();
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	glWindow_ = glfwCreateWindow(window_width, window_height, name_.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(glWindow_);

	//glfwSetFramebufferSizeCallback(glWindow_, framebuffer_size_callback);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		//std::cout << "Failed to initialize GLAD" << std::endl;
		return ;
	}

	// Define the viewport dimensions
	glViewport(0, 0, window_width, window_height);

	ShaderLoader::GetInstance().Startup();

	Startup();
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

void App::Startup()
{

}

void App::Run()
{
	Create();

	frameTime_ = 1000 / FPS_;

	RenderEngine& re = Context::GetInstance().RenderEngineInstance();

	Timer timer;

	while (!glfwWindowShouldClose(glWindow_))
	{
		timer.Begin();

		CpuRegion _region("App::Run");

		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		re.Refresh();

		glfwSwapBuffers(glWindow_);

		timer.End();
		auto milli = timer.Milliseconds();
		if (milli >= frameTime_) continue;

		std::this_thread::sleep_for(std::chrono::milliseconds(frameTime_ - milli));
	}

	glfwTerminate();
}

void App::Quit()
{

}

NS_RENDER_END