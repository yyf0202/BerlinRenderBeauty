#pragma once

#include "IActionManager.h"

NS_RENDER_BEGIN

class SeqActionManager : public IActionManager
{
public:
	virtual void OnStart() override;
	virtual void OnUpdate() override;
	virtual void OnFinish() override;

	virtual void Add(IAction* action) override;
	virtual void Rem(IAction* action) override;

private:
	vector_t<IAction*> actions_;
};

NS_RENDER_END