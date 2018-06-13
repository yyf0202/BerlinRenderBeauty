
#include "Material.h"
#include "Shader.h"
#include <BerlinRenderer/Base/Context.h>
#include <BerlinRenderer/Resources/ResourceManager.h>

NS_RENDER_BEGIN

Material::Material()
{
}

Material::Material(Shader* shader)
	: shader_(shader)
{
}

Material::~Material()
{
}

Material& Material::GetDefaultMaterial()
{
	static Material def(Context::GetInstance().ResourceManagerInstance().GetDefaultShader());
	return def;
}

void Material::SetShaderPath(string_t path)
{
	shader_ = Context::GetInstance().ResourceManagerInstance().Load<Shader>(path);
	if (shader_ == nullptr)
	{
		shader_ = Context::GetInstance().ResourceManagerInstance().GetDefaultShader();
	}
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