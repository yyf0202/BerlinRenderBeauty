//0.1.1
//初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#ifndef _APP_H
#define _APP_H
#pragma once
#include "PreDeclare.h"

namespace BRE {
	class App : boost::noncopyable
	{
	public:
		App();
		~App();

		void Create();
		void Destroy();
		void Suspend();
		void Resume();
		void Refresh();


		void Run();
		void Quit();
	};
}
#endif