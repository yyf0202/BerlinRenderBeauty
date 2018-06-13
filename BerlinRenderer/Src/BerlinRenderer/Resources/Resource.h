#pragma once

#include <BerlinRenderer/Base/Config.h>
#include "IResource.h"

NS_RENDER_BEGIN

template<typename _TLoader>
class RENDER_API Resource : public IResource
{
public:
	typedef _TLoader Loader;
public:
	GLuint GetGPUOjbectId() const { return id_; }

protected:
	GLuint id_;
};

NS_RENDER_END