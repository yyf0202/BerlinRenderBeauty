#pragma once

#include "Action.h"

NS_RENDER_BEGIN

class IActionManager : public Action
{
public:
	virtual void Add(IAction* action) = 0;
	virtual void Rem(IAction* action) = 0;

protected:
	void SetActionManager(IAction& action, IActionManager& manager) { action.SetActionManager(manager); }
	void SetActionStatus(IAction& action, EActionStatus status) { action.SetStatus(status); }
};

NS_RENDER_END