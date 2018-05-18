//0.1.1
//初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#ifndef _APP_H
#define _APP_H
#pragma once
#include "PreDeclare.h"
#include "Context.h"
#include <string>

namespace BRE {
	class App : boost::noncopyable
	{
	public:
		App(std::string const & name);
		~App();

		void Create();
		void Destroy();
		void Suspend();
		void Resume();
		void Refresh();


		void Run();
		void Quit();

	private:
		void Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mode);
		std::string name_;
		int window_width;
		int window_height;
		GLFWwindow* glWindow_;
	};
}
#endif