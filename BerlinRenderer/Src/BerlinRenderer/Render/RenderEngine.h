// 0.1.1
// 初次创建 (2018.05.10)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#pragma once
#include <BerlinRenderer\Base\Config.h>
#include <BerlinRenderer\Base\Context.h>

NS_RENDER_BEGIN

class Camera;

class RENDER_API RenderEngine : Noncopyable
{
public:
	RenderEngine();
	~RenderEngine();
	void Refresh();
};

NS_RENDER_END