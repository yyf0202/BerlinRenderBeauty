#pragma once

#include <BerlinRenderer/Base/Config.h>
#include <BerlinRenderer/Base/Singleton.h>

#include "../Material/Shader.h"

NS_RENDER_BEGIN

class ShaderLoader : public Singleton<ShaderLoader>
{
public:
	shared_ptr_t<Shader> Load(string_t path);

	error_t Startup();

private:
	shared_ptr_t<Shader> _loadByContent(string_t& vert, string_t& frag);

private:
	Shader* default_ = nullptr;

private:
	hash_t<string_t, shared_ptr_t<Shader>> shaders_;
};

NS_RENDER_END