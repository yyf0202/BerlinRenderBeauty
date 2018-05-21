// 0.1.1
// 初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#include <BerlinRenderer\App\App.h>

namespace BRE {
	App::App(std::string const & name)
		: name_(name), window_width(0),
		window_height(0)
	{



	}

	App::~App() {

	}

	void App::Create() {
		glfwInit();
		// Set all the required options for GLFW
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		glWindow_ = glfwCreateWindow(window_width, window_height, name_.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(glWindow_);

		// Set the required callback functions
		glfwSetKeyCallback(glWindow_, this->Key_Callback);

		// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
		glewExperimental = GL_TRUE;
		// Initialize GLEW to setup the OpenGL Function pointers
		glewInit();

		// Define the viewport dimensions
		glViewport(0, 0, window_width, window_height);
	}

	void App::Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mode)
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);
	}

	void App::Destroy() {

	}

	void App::Suspend() {

	}

	void App::Resume() {

	}

	void App::Refresh() {

	}

	void App::Run() {
		RenderEngine& re = Context::Instance().RenderEngineInstance();
		SceneManager& sm = Context::Instance().SceneManagerInstance();

		while (!glfwWindowShouldClose(glWindow_))
		{
			// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
			glfwPollEvents();

			// Render
			// Clear the colorbuffer
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			re.Refresh();

			glfwSwapBuffers(glWindow_);
		}

		glfwTerminate();
	}

	void App::Quit() {

	}
}