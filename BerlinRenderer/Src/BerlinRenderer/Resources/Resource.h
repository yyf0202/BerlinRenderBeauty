#pragma once

#include <BerlinRenderer/Base/Config.h>

NS_RENDER_BEGIN

class RENDER_API Resource : std::enable_shared_from_this<Resource> // TODO: from object?
{
public:
	GLuint GetGPUOjbectId() const { return id_; }

protected:
	GLuint id_;
};

NS_RENDER_END