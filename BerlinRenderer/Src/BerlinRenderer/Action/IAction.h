#pragma once

#include <BerlinRenderer/Base/Config.h>

NS_RENDER_BEGIN

class IActionManager;

enum EActionStatus
{
	E_READY,
	E_RUNNING,
	E_FINISH,
};

class IAction
{
public:
	virtual void OnStart() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnFinish() = 0;
	virtual EActionStatus GetStatus() = 0;
	virtual IActionManager* GetManager() = 0;

protected:
	virtual void SetActionManager(IActionManager& actionManager) = 0;
	virtual void SetStatus(EActionStatus status) = 0;

	friend IActionManager;
};

NS_RENDER_END