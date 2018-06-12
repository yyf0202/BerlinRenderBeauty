#pragma once

#include <BerlinRenderer/Base/Config.h>
#include <BerlinRenderer/Base/Singleton.h>

#include "../Material/Shader.h"
#include "Loader.h"

NS_RENDER_BEGIN

class ShaderLoader : public Loader<Shader>
{
public:
	ShaderLoader(string_t path, function_t<void(Shader*)> loaded) : Loader(path, loaded) { }

	static Shader* Load(string_t path);

	virtual void BeginTask() override;
	virtual void EndTask() override;

private:
	static Shader* default_;
};

NS_RENDER_END