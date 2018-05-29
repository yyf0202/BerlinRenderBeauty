// 0.1.1 
// 初次创建 (2018.05.10)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#pragma once
#include <BerlinRenderer\Base\Config.h>
#include <BerlinRenderer\Resources\Mesh.h>
#include <BerlinRenderer\Scene Manager\SceneObject.h>
#include <BerlinRenderer\Base\Context.h>
#include "Shader.h"

NS_RENDER_BEGIN

class Renderer : Noncopyable
{
public:
	Renderer(SceneObject* sceneObject);
	~Renderer();
	void Draw();

private:
	Mesh mesh_;
	Shader* shader_;
	SceneObject* object_;
};

NS_RENDER_END