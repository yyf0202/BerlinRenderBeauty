#pragma once

#include "Config.h"

NS_RENDER_BEGIN

class Timer
{
public:
	Timer();
	~Timer();

	void Begin();
	void End();
	void Reset();

	uint32_t Milliseconds();

private:
	ptr_t platform_ = nullptr;
	uint32_t milliseconds_ = 0;
};

NS_RENDER_END