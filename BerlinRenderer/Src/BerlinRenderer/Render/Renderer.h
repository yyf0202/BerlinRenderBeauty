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

class Material;

class Renderer : Noncopyable
{
public:
	Renderer(SceneObject* sceneObject);
	~Renderer();
<<<<<<< HEAD

	virtual void Render() = 0;

	void SetMaterial(Material* mat) { mat_ = mat; }
	Material* GetMaterial() { return mat_; }

protected:
	Material * mat_ = nullptr;
=======
	void Draw();

private:
	Mesh mesh_;
	Shader* shader_;
	SceneObject* object_;
>>>>>>> 7dbbfcca7c33c3819308d944f04632e830b2ffbb
};

NS_RENDER_END