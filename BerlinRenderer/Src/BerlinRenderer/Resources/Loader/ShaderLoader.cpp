
#include "ShaderLoader.h"

#include "../FileManager.h"

static string_t _s_def_vert = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}";
static string_t _s_def_frag = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(0.5f, 0.5f, 0.5f, 0.5f);\n"
	"}\n";

NS_RENDER_BEGIN

void ShaderLoader::BeginTask()
{
	resource_ = Load(path_);
}

void ShaderLoader::EndTask()
{
	loaded_(resource_);
}

Shader* ShaderLoader::Load(string_t path)
{
	do
	{
		auto content_vert = FileManager::GetInstance().Read(path + ".vert");
		if (content_vert == "") break;

		auto content_frag = FileManager::GetInstance().Read(path + ".frag");
		if (content_frag == "") break;

		auto sd = new Shader();
		if (sd->Compile(content_vert, content_frag)) break;

		if (sd->Attach()) break;

		if (sd->Link()) break;

		return sd;
	} while (false);

	return nullptr;
}

NS_RENDER_END