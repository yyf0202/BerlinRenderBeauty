#pragma once

#include <BerlinRenderer/Base/Config.h>

NS_RENDER_BEGIN

class Shader;

class Material
{
public:
	Material();
	Material(Shader* shader);
	~Material();

	void SetShaderPath(string_t path);
	void Use();

	void SetBool(const std::string &name, bool value) const;
	void SetInt(const std::string &name, int value) const;
	void SetFloat(const std::string &name, float value) const;
	void SetMat4(const std::string &name, const glm::mat4 &mat) const;

private:
	Shader * shader_ = nullptr;
};

NS_RENDER_END