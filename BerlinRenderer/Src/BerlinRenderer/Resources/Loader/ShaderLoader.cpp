
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

error_t ShaderLoader::Startup()
{
	default_ = _loadByContent(_s_def_vert, _s_def_frag).get();
	if (default_ == nullptr) return -1;

	shaders_["default"] = shared_ptr_t<Shader>(default_);

	return 0;
}


shared_ptr_t<Shader> ShaderLoader::Load(string_t path)
{
	auto fd = shaders_.find(path);
	if (fd != shaders_.end()) return fd->second;

	do
	{
		auto content_vert = FileManager::GetInstance().Read(path + ".vert");
		if (content_vert == "") break;

		auto content_frag = FileManager::GetInstance().Read(path + ".frag");
		if (content_frag == "") break;

		auto sd = _loadByContent(content_vert, content_frag);
		if (sd == nullptr) break;

		shaders_[path] = shared_ptr_t<Shader>(sd);
	} while (false);

	return shared_ptr_t<Shader>(default_);
}

shared_ptr_t<Shader> ShaderLoader::_loadByContent(string_t& vert, string_t& frag)
{
	do
	{
		auto sd = new Shader();
		if (sd->Compile(vert, frag)) break;

		if (sd->Attach()) break;

		if (sd->Link()) break;

		return shared_ptr_t<Shader>(sd);
	} while (false);

	return shared_ptr_t<Shader>(default_);
}

NS_RENDER_END