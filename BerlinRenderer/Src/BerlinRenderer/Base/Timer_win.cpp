
#include "Timer.h"

#ifdef WIN32

#include <Windows.h>

NS_RENDER_BEGIN

static LARGE_INTEGER _s_freq = { 0 };
static bool_t _init_freq()
{
	LARGE_INTEGER freq = { 0 };
	QueryPerformanceFrequency(&_s_freq);
	return true;
}
static bool_t _auto_init_freq = _init_freq();


Timer::Timer()
{
	platform_ = new LARGE_INTEGER();
}

Timer::~Timer()
{
	SAFE_DEL(platform_);
}

void Timer::Begin()
{
	LARGE_INTEGER begin = *(LARGE_INTEGER*)platform_;
	QueryPerformanceCounter(&begin);
}

void Timer::End()
{
	LARGE_INTEGER now;
	QueryPerformanceCounter(&now);

	milliseconds_ = (float(now.QuadPart - (*(LARGE_INTEGER*)platform_).QuadPart)) / _s_freq.QuadPart * 1000;
}

uint32_t Timer::Milliseconds()
{
	return milliseconds_;
}

NS_RENDER_END

#endif