// 0.1.1
// 初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#ifndef _SCENEMANAGER_H
#define _SCENEMANAGER_H
#pragma once
#include "PreDeclare.h"

namespace BRE {
	class SceneManager : boost::noncopyable
	{
	public:
		SceneManager();
		virtual ~SceneManager();
	};
}
#endif