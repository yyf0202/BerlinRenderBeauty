#pragma once

#include "Config.h"

NS_RENDER_BEGIN

class Noncopyable
{
protected:
	Noncopyable() = default;
	~Noncopyable() = default;

	Noncopyable(const Noncopyable&) = delete;
	Noncopyable& operator=(const Noncopyable&) = delete;
};

NS_RENDER_END