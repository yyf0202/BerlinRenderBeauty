//0.1.1
//初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#pragma once

#include <BerlinRenderer/Base/Config.h>

struct GLFWwindow;

NS_RENDER_BEGIN

class RENDER_API App : Noncopyable
{
public:
	App(string_t const & name);
	~App();

	void Create();
	void Destroy();
	void Suspend();
	void Resume();
	void Refresh();


	void Run();
	void Quit();

	virtual void Startup();

private:
	void Key_Callback(GLFWwindow* window, int32_t key, int32_t scancode, int32_t action, int32_t mode);
	string_t name_;
	int32_t window_width;
	int32_t window_height;
	GLFWwindow* glWindow_;

	uint32_t FPS_ = 60;
	uint32_t frameTime_ = 0;
};

NS_RENDER_END