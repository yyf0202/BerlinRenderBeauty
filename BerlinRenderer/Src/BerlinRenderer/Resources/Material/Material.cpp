
#include "Material.h"
#include "Shader.h"
#include "../Loader/ShaderLoader.h"

NS_RENDER_BEGIN

Material::Material()
{
}

Material::~Material()
{
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


NS_RENDER_END