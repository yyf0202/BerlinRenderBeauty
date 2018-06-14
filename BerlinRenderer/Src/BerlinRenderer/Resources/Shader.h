#pragma once

#include <BerlinRenderer\Base\Config.h>
#include "../Resource.h"

NS_RENDER_BEGIN

class ShaderLoader;

class Shader : public Resource
{
public:
	Shader();
	~Shader();

	virtual void Load(string_t path) override;

	void Active();

	error_t Compile(string_t vert_code, string_t frag_code);
	error_t Attach();
	error_t Link();

	GLuint GetId() { return progamId_; }

private:
	error_t _compile(string_t code, uint32_t type);
	void CheckError(GLuint shader, GLbyte status);

private:
	bool compile_failed_;
	GLuint shader_ids_[2] = { 0 };
	GLuint progamId_ = 0;
};



NS_RENDER_END
