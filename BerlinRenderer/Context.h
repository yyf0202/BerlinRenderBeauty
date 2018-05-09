//0.1.1
//初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#ifndef _CONTEXT_H
#define _CONTEXT_H
#pragma once
#include "PreDeclare.h"

namespace BRE {
	class Context : boost::noncopyable
	{
	public:
		Context();
		~Context();

		static Context& Instance();
		static void Destroy();
		void Suspend();
		void Resume();

	private:
	
		static std::unique_ptr<Context> context_instance_;
	};
}
#endif
