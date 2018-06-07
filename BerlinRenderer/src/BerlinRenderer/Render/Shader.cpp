// 0.1.1 
// 初次创建 (2018.05.10)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#include <BerlinRenderer\Render\Shader.h>

NS_RENDER_BEGIN

Shader::Shader(const GLchar * vertexPath, const GLchar * fragmentPath)
{

}

Shader::Shader()
{
	compile_failed_ = true;

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

		compile_failed_ = false;
	}

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(vertexShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	int success;
	char loginfo[1024];
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(fragmentShader, 1024, NULL, loginfo);
		std::cout << "ERROR::SHADER_COMPILATION_ERROR : " << loginfo << "\n -- --------------------------------------------------- -- " << std::endl;

		compile_failed_ = false;
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

		compile_failed_ = false;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glUseProgram(shaderProgramm);
}

Shader::~Shader()
{

}

void Shader::SetBool(const std::string &name, bool value) const
{
	glUniform1i(glGetUniformLocation(program_, name.c_str()), (int)value);
}

void Shader::SetInt(const std::string &name, int value) const
{
	glUniform1i(glGetUniformLocation(program_, name.c_str()), value);
}

void Shader::SetFloat(const std::string &name, float value) const
{
	glUniform1f(glGetUniformLocation(program_, name.c_str()), value);
}

void Shader::SetMat4(const std::string &name, const glm::mat4 &mat) const
{
	glUniformMatrix4fv(glGetUniformLocation(program_, name.c_str()),1, GL_FALSE, &mat[0][0]);
}

void Shader::Use()
{
	glUseProgram(this->program_);
}

NS_RENDER_END