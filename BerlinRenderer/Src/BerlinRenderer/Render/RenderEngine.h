// 0.1.1
// 初次创建 (2018.05.10)
//
// 修改记录
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