//0.1.1
//���δ��� (2018.05.09)
//
// �޸ļ�¼
///////////////////////////////////////////////////////////////////

#pragma once
#include <boost/noncopyable.hpp>
#include <memory>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace BRE {
	class SceneObject;
	typedef std::shared_ptr<SceneObject> SceneObjectPtr;

	class Renderable;
	typedef std::shared_ptr<Renderable> RenderablePtr;
}