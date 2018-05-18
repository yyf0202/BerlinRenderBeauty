//0.1.1
//初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#ifndef _PREDECLARE_H
#define _PREDECLARE_H
#pragma once
#include <boost/noncopyable.hpp>
#include <memory>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace BRE {
	class SceneObject;
	typedef std::shared_ptr<SceneObject> SceneObjectPtr;

	class Renderable;
	typedef std::shared_ptr<Renderable> RenderablePtr;
}
#endif