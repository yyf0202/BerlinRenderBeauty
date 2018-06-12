#pragma once

#include <BerlinRenderer/Base/Config.h>

NS_RENDER_BEGIN

class ITask
{
public:
	virtual void BeginTask() = 0;
	virtual void EndTask() = 0;
};

NS_RENDER_END