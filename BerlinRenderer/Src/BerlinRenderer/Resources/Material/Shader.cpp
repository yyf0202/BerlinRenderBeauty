// 0.1.1 
// 初次创建 (2018.05.10)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#include "Shader.h"

NS_RENDER_BEGIN

Shader::Shader()
{
	progamId_ = glCreateProgram();
}

Shader::~Shader()
{
	glDeleteProgram(progamId_);
	progamId_ = 0;
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
	CHECK_OPENGL();

	if (compiled == GL_FALSE)
	{
#ifdef OPEN_GL_LOG
		GL_LOG("shader source: %s\n", code);
		GL_LOG("==========shader source end=======\n");

		GLint len;
		GLchar* log;
		glGetShaderiv(m_shader_id, GL_INFO_LOG_LENGTH, &len);

		log = new GLchar[len];
		glGetShaderInfoLog(m_shader_id, len, &len, log);
		GL_LOG("compile log ='%s '\n", log);
		delete log;
#endif
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

	GLint linked;
	glGetProgramiv(progamId_, GL_LINK_STATUS, &linked);

	if (!linked)
	{
		//#ifdef OPEN_GL_LOG
		static GLchar infoLog[512];
		glGetProgramInfoLog(progamId_, 512, nullptr, infoLog);
		std::cout << "link log ='%s '\n" << infoLog;
		//#endif
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

	return 0;
}

void Shader::CheckError(GLuint shader, GLbyte status)
{
	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(shader, status, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
}

NS_RENDER_END