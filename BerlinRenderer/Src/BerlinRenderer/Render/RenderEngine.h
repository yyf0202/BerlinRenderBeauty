// 0.1.1
// ���δ��� (2018.05.10)
//
// �޸ļ�¼
///////////////////////////////////////////////////////////////////

#pragma once
#include <BerlinRenderer\Base\PreDeclare.h>

namespace BRE {

	class RenderEngine : boost::noncopyable
	{
	public:
		RenderEngine();
		~RenderEngine();
		void Refresh();
	};
}