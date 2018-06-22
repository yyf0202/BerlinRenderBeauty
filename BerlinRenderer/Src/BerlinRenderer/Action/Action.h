#pragma once

#include "IAction.h"

NS_RENDER_BEGIN

class Action : public IAction
{
public:
	virtual void OnStart() override {};
	virtual void OnUpdate() override {};
	virtual void OnFinish() override {};
	virtual EActionStatus GetStatus() override { return status_; }
	virtual IActionManager* GetManager() override { return manager_; }

protected:
	virtual void SetStatus(EActionStatus status) override { status_ = status; }
	virtual void SetActionManager(IActionManager& actionManager) override { manager_ = &actionManager; }

private:
	EActionStatus status_ = EActionStatus::E_READY;
	IActionManager* manager_ = nullptr;
};

NS_RENDER_END