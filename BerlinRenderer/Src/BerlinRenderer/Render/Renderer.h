// 0.1.1 
// ���δ��� (2018.05.10)
//
// �޸ļ�¼
///////////////////////////////////////////////////////////////////

#pragma once
#include <BerlinRenderer\Base\Config.h>

NS_RENDER_BEGIN

class Material;
class Camera;
class SceneObject;

class Renderer : Noncopyable
{
public:
	Renderer();
	~Renderer();

	virtual void Draw(Camera* camera);

	void SetMaterial(Material* mat);
	Material* GetMaterial();

	inline void SetObject(SceneObject* obj) { object_ = obj; }
	inline SceneObject& GetObject() { return *object_; }

protected:
	Material * mat_ = nullptr;
	SceneObject* object_ = nullptr;
};

NS_RENDER_END