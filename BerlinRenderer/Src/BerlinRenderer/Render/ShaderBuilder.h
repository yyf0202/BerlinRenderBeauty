#pragma once
#include "stdafx.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class ShaderBuilder
{
	const char *vertexShaderSourceTriangle = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
	const char *fragmentShaderSourceTriangle = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n\0";
public:
	ShaderBuilder();
	~ShaderBuilder();

private:

};

ShaderBuilder::ShaderBuilder()
{
	
}

ShaderBuilder::~ShaderBuilder()
{

}