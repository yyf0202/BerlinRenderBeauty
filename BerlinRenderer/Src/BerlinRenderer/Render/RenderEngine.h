// 0.1.1
// ���δ��� (2018.05.10)
//
// �޸ļ�¼
///////////////////////////////////////////////////////////////////

#pragma once
#include <BerlinRenderer\Base\Config.h>

NS_RENDER_BEGIN

class RENDER_API RenderEngine : Noncopyable
{
public:
	RenderEngine();
	~RenderEngine();
	void Refresh();
};

NS_RENDER_END