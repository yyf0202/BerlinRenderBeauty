#pragma once


#define NS_RENDER_BEGIN		namespace BRE {
#define NS_RENDER_END		}
#define NS_RENDER			BRE::
#define USE_RENDER			

#define OPEN_RENDER_DLL_API

#ifdef OPEN_RENDER_DLL_API
#define RENDER_API	__declspec(dllexport)
#else
//#define RENDER_API	__declspec(dllimport)
#define RENDER_API
#endif


//#include <boost/noncopyable.hpp>