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