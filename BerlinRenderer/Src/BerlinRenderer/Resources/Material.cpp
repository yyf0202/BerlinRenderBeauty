
#include "Material.h"
#include "Shader.h"
#include <BerlinRenderer/Base/Context.h>
#include <BerlinRenderer/Resources/ResourceManager.h>
#include <BerlinRenderer/IO/LoggerManager.h>

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

void Material::SetShaderPath(string_t path)
{
	shader_ = Context::GetInstance().ResourceManagerInstance().Load<Shader>(path);
	if (shader_ == nullptr)
	{
		LOG_WARNING("load shader %s failed", path.c_str());
	}
}

void Material::Use()
{
	shader_->Active();
	//SetInt("mainTexture", 0);
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