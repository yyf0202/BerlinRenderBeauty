<<<<<<< HEAD
//#ifndef SHADER_H
//#define SHADER_H
//
//
//#include <BerlinRenderer/Base/Config.h>
//
//#include <string>
//#include <fstream>
//#include <sstream>
//#include <iostream>
//#include <BerlinRenderer\Base\Config.h>
//
//NS_RENDER_BEGIN
//class Shader
//{
//public:
//	GLuint Program;
//	// Constructor generates the shader on the fly
//	Shader(const GLchar* vertexPath, const GLchar* fragmentPath)
//	{
//		// 1. Retrieve the vertex/fragment source code from filePath
//		std::string vertexCode;
//		std::string fragmentCode;
//		std::ifstream vShaderFile;
//		std::ifstream fShaderFile;
//		// ensures ifstream objects can throw exceptions:
//		vShaderFile.exceptions(std::ifstream::badbit);
//		fShaderFile.exceptions(std::ifstream::badbit);
//		try
//		{
//			// Open files
//			vShaderFile.open(vertexPath);
//			fShaderFile.open(fragmentPath);
//			std::stringstream vShaderStream, fShaderStream;
//			// Read file's buffer contents into streams
//			vShaderStream << vShaderFile.rdbuf();
//			fShaderStream << fShaderFile.rdbuf();
//			// close file handlers
//			vShaderFile.close();
//			fShaderFile.close();
//			// Convert stream into string
//			vertexCode = vShaderStream.str();
//			fragmentCode = fShaderStream.str();
//		}
//		catch (std::ifstream::failure e)
//		{
//			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
//		}
//		const GLchar* vShaderCode = vertexCode.c_str();
//		const GLchar * fShaderCode = fragmentCode.c_str();
//		// 2. Compile shaders
//		GLuint vertex, fragment;
//		GLint success;
//		GLchar infoLog[512];
//		// Vertex Shader
//		vertex = glCreateShader(GL_VERTEX_SHADER);
//		glShaderSource(vertex, 1, &vShaderCode, NULL);
//		glCompileShader(vertex);
//		// Print compile errors if any
//		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
//		if (!success)
//		{
//			glGetShaderInfoLog(vertex, 512, NULL, infoLog);
//			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//		}
//		// Fragment Shader
//		fragment = glCreateShader(GL_FRAGMENT_SHADER);
//		glShaderSource(fragment, 1, &fShaderCode, NULL);
//		glCompileShader(fragment);
//		// Print compile errors if any
//		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
//		if (!success)
//		{
//			glGetShaderInfoLog(fragment, 512, NULL, infoLog);
//			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//		}
//		// Shader Program
//		this->Program = glCreateProgram();
//		glAttachShader(this->Program, vertex);
//		glAttachShader(this->Program, fragment);
//		glLinkProgram(this->Program);
//		// Print linking errors if any
//		glGetProgramiv(this->Program, GL_LINK_STATUS, &success);
//		if (!success)
//		{
//			glGetProgramInfoLog(this->Program, 512, NULL, infoLog);
//			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//		}
//		// Delete the shaders as they're linked into our program now and no longer necessery
//		glDeleteShader(vertex);
//		glDeleteShader(fragment);
//
//	}
//	// Uses the current shader
//	void Draw()
//	{
//		glUseProgram(this->Program);
//	}
//};
//NS_RENDER_END
//#endif
=======
#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <BerlinRenderer\Base\Config.h>

NS_RENDER_BEGIN

class Shader
{
public:
	//default shader,
	Shader::Shader();

	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	~Shader();

	void SetBool(const std::string &name, bool value) const;
	void SetInt(const std::string &name, int value) const;
	void SetFloat(const std::string &name, float value) const;
	void SetMat4(const std::string &name, const glm::mat4 &mat) const;
	void Use();

private:
	GLuint program_;
	bool compile_failed_;


	const char *fragmentShaderSource =
		"#version 330 core\n"
		"out vec4 FragColor;\n"

		"in vec2 TexCoord; \n"

		"uniform sampler2D diffuse;\n"
		"uniform sampler2D specular;\n"

		"void main()\n"
		"{\n"
		"   FragColor = texture(diffuse,TexCoord);\n"
		"}\n\0";


	const char *vertexShaderSource =
		"#version 330 core\n"
		"layout(location = 0) in vec3 position;\n"
		"layout(location = 1) in vec3 normal;\n"
		"layout(location = 2) in vec2 uv;\n"

		"out vec2 TexCoord;\n"

		"uniform mat4 model;\n"
		"uniform mat4 view;\n"
		"uniform mat4 projection;\n"

		"void main()\n"
		"{\n"
		"	gl_Position = projection * view * model * vec4(position, 1.0f);\n"
		"	TexCoord = vec2(uv.x, uv.y);\n"
		"}\n\0";
};

NS_RENDER_END
#endif
>>>>>>> 7dbbfcca7c33c3819308d944f04632e830b2ffbb
