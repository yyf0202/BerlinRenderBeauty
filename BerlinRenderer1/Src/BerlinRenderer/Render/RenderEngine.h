// 0.1.1
// ���δ��� (2018.05.10)
//
// �޸ļ�¼
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