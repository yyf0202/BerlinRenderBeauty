#pragma once

#include "Config.h"

NS_RENDER_BEGIN

template<class _Ty>
class Singleton
{
public:
	static _Ty& GetInstance()
	{
		static _Ty s_inst;
		return s_inst;
	}

protected:
	Singleton() {}
};

NS_RENDER_END