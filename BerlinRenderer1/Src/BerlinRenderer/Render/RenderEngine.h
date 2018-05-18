// 0.1.1
// 初次创建 (2018.05.10)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#pragma once

#include <BerlinRenderer/Config.h>

NS_RENDER_BEGIN

class RENDER_API RenderEngine : boost::noncopyable
{
public:
	RenderEngine();
	~RenderEngine();
	void Refresh();

	void Test();
};

NS_RENDER_END