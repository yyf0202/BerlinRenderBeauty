//0.1.1
//初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////
#ifndef _SCENEOBJECT_H
#define _SCENEOBJECT_H
#pragma once
#include "PreDeclare.h"

namespace BRE {

	class SceneObject : boost::noncopyable
	{
	public:
		SceneObject();
		virtual ~SceneObject();
	};

}
#endif