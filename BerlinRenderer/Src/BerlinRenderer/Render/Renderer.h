// 0.1.1 
// ���δ��� (2018.05.10)
//
// �޸ļ�¼
///////////////////////////////////////////////////////////////////

#pragma once
#include <BerlinRenderer\Base\Config.h>

NS_RENDER_BEGIN

class Material;

class Renderer : Noncopyable
{
public:
	Renderer();
	~Renderer();

	virtual void Draw();

	void SetMaterial(Material* mat);
	Material* GetMaterial();

protected:
	Material * mat_ = nullptr;
};

NS_RENDER_END