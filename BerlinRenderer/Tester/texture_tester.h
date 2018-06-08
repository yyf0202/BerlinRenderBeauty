#pragma once

#include <BerlinRenderer\Base\Config.h>
#include <iostream>

namespace tester
{
	class TexuterTester
	{
	public:
		static bool Run()
		{
			Init();

			GLuint vertexShader, fragmentShader;
			vertexShader = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
			glCompileShader(vertexShader);
			int success;
			char loginfo[1024];
			glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

			if (!success) {
				glGetShaderInfoLog(vertexShader, 1024, NULL, loginfo);
				std::cout << "ERROR::SHADER_COMPILATION_ERROR : " << loginfo << "\n -- --------------------------------------------------- -- " << std::endl;
			}

			fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
			glCompileShader(fragmentShader);
			int success;
			char loginfo[1024];
			glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

			if (!success) {
				glGetShaderInfoLog(fragmentShader, 1024, NULL, loginfo);
				std::cout << "ERROR::SHADER_COMPILATION_ERROR : " << loginfo << "\n -- --------------------------------------------------- -- " << std::endl;
			}

			unsigned int shaderProgramm;
			shaderProgramm = glCreateProgram();
			glAttachShader(shaderProgramm, vertexShader);
			glAttachShader(shaderProgramm, fragmentShader);
			glLinkProgram(shaderProgramm);

			glGetProgramiv(shaderProgramm, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(shaderProgramm, 1024, NULL, loginfo);
				std::cout << "ERROR::PROGRAMM_LINK_ERROR :" << loginfo << "\n -- --------------------------------------------------- -- " << std::endl;
			}

			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			glUseProgram(shaderProgramm);
		}


#pragma region Shader source code
		const char *vertexShaderSource =
			"#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"void main()\n"
			"{\n"
			"   gl_Position = vec4(aPos, 1.0);\n"
			"}\0";

		const char *fragmentShaderSource =
			"#version 330 core\n"
			"out vec4 FragColor;\n"
			"uniform vec4 ourColor;\n"
			"void main()\n"
			"{\n"
			"   FragColor = ourColor;\n"
			"}\n\0";
#pragma endregion

#pragma region GLInit
		static void Init() {
			glfwInit();
			// Set all the required options for GLFW
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
			GLFWwindow* glWindow_ = glfwCreateWindow(800, 600, "Main", nullptr, nullptr);
			glfwMakeContextCurrent(glWindow_);
			glfwSetFramebufferSizeCallback(glWindow_, framebuffer_size_callback);

			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				std::cout << "Failed to initialize GLAD" << std::endl;
				return;
			}
		}
		void framebuffer_size_callback(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}
#pragma endregion
	};

}