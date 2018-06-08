
#include "Material.h"
#include "Shader.h"
#include "../Loader/ShaderLoader.h"

NS_RENDER_BEGIN

Material::Material()
{
}

Material::Material(string_t path)
{
	SetShaderPath(path);
}

Material::~Material()
{
}

Material& Material::GetDefaultMaterial()
{
	static Material def("default");
	return def;
}

void Material::SetShaderPath(string_t path)
{
	shader_ = ShaderLoader::GetInstance().Load(path).get();
	if (shader_ == nullptr) return;
}

void Material::Use()
{
	shader_->Active();
}

void Material::SetBool(const std::string &name, bool value) const
{
	glUniform1i(glGetUniformLocation(shader_->GetId(), name.c_str()), (int)value);
}

void Material::SetInt(const std::string &name, int value) const
{
	glUniform1i(glGetUniformLocation(shader_->GetId(), name.c_str()), value);
}

void Material::SetFloat(const std::string &name, float value) const
{
	glUniform1f(glGetUniformLocation(shader_->GetId(), name.c_str()), value);
}

void Material::SetMat4(const std::string &name, const glm::mat4 &mat) const
{
	glUniformMatrix4fv(glGetUniformLocation(shader_->GetId(), name.c_str()), 1, GL_FALSE, &mat[0][0]);
}


NS_RENDER_END