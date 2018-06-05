#pragma once

#include <BerlinRenderer/Base/Config.h>

NS_RENDER_BEGIN

class Shader;

class Material
{
public:
	Material();
	~Material();

	void SetShaderPath(string_t path);
	void Use();

private:
	Shader * shader_ = nullptr;
};

NS_RENDER_END