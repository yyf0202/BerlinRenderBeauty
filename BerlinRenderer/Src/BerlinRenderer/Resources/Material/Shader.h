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
	Shader();
	~Shader();

	void Active();

	error_t Compile(string_t vert_code, string_t frag_code);
	error_t Attach();
	error_t Link();

	GLuint GetId() { return progamId_; }

private:
	error_t _compile(string_t code, uint32_t type);

private:
	bool compile_failed_;
	GLuint shader_ids_[2] = { 0 };
	GLuint progamId_ = 0;
};
NS_RENDER_END
#endif