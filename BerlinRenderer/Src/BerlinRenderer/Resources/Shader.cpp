// 0.1.1 
// 初次创建 (2018.05.10)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#include "Shader.h"
#include <BerlinRenderer/IO/FileManager.h>
#include <BerlinRenderer/IO/LoggerManager.h>

NS_RENDER_BEGIN

Shader::Shader()
{
	progamId_ = glCreateProgram();

	glBindAttribLocation(progamId_, VERTEX_SHADER_ATTRIBUTE_POSITION_LAYOUT, VERTEX_SHADER_ATTRIBUTE_POSITION_NAME);
	glBindAttribLocation(progamId_, VERTEX_SHADER_ATTRIBUTE_COLOR_LAYOUT, VERTEX_SHADER_ATTRIBUTE_COLOR_NAME);
	glBindAttribLocation(progamId_, VERTEX_SHADER_ATTRIBUTE_UV_LAYOUT, VERTEX_SHADER_ATTRIBUTE_UV_NAME);
}

Shader::~Shader()
{
	glDeleteProgram(progamId_);
	progamId_ = 0;
}

void Shader::Load(string_t path)
{
	path_ = path;
	do
	{
		auto content_vert = FileManager::GetInstance().Read(path_ + ".vert");
		if (content_vert == "") break;

		auto content_frag = FileManager::GetInstance().Read(path_ + ".frag");
		if (content_frag == "") break;

		if (Compile(content_vert, content_frag)) break;

		if (Attach()) break;

		if (Link()) break;
	} while (false);

	return;
}

void Shader::Active()
{
	glUseProgram(progamId_);
	CHECK_OPENGL();
}

error_t Shader::_compile(string_t code, uint32_t type)
{
	static GLuint stype[2] = { GL_VERTEX_SHADER , GL_FRAGMENT_SHADER };

	shader_ids_[type] = glCreateShader(stype[type]);

	const char* c = code.c_str();
	glShaderSource(shader_ids_[type], 1, &c, nullptr);
	glCompileShader(shader_ids_[type]);
	GLint compiled;
	glGetShaderiv(shader_ids_[type], GL_COMPILE_STATUS, &compiled);

	if (compiled == GL_FALSE)
	{
		static GLchar infoLog[512];
		glGetShaderInfoLog(shader_ids_[type], 512, nullptr, infoLog);
		LOG_ERROR("link shader error %s", infoLog);
		return -1;
	}

	return 0;
}

error_t Shader::Compile(string_t vert_code, string_t frag_code)
{
	auto ret = _compile(vert_code, 0);
	if (ret != 0) return ret;

	ret = _compile(frag_code, 1);
	if (ret != 0) return ret;

	return 0;
}

error_t Shader::Link()
{
	glLinkProgram(progamId_);
	CHECK_OPENGL();

	GLint linked;
	glGetProgramiv(progamId_, GL_LINK_STATUS, &linked);

	if (!linked)
	{
		static GLchar infoLog[512];
		glGetProgramInfoLog(progamId_, 512, nullptr, infoLog);
		LOG_ERROR("link shader error %s", infoLog);

		return -1;
	}
	return 0;
}

error_t Shader::Attach()
{
	glAttachShader(progamId_, shader_ids_[0]);
	glAttachShader(progamId_, shader_ids_[1]);

	glDeleteShader(shader_ids_[0]);
	glDeleteShader(shader_ids_[1]);

	CHECK_OPENGL();

	return 0;
}

void Shader::CheckError(GLuint shader, GLbyte status)
{
	GLint success;
	static char infoLog[512];
	glGetShaderiv(shader, status, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		LOG_ERROR("shader compile error %s", infoLog);
	}
}

NS_RENDER_END