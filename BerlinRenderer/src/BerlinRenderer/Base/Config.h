#pragma once

#define NS_RENDER_BEGIN		namespace BRE {
#define NS_RENDER_END		}
#define RENDER				BRE::
#define USE_RENDER			


#include <boost/noncopyable.hpp>


#define OPEN_RENDER_API

#ifdef OPEN_RENDER_API
#define RENDER_API __declspec(dllexport)
#else
#define RENDER_API
#endif
