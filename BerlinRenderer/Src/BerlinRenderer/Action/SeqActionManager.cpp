
#include "SeqActionManager.h"

NS_RENDER_BEGIN

void SeqActionManager::OnStart()
{

}

void SeqActionManager::OnUpdate()
{
	for(auto iter = actions_.begin(); iter != actions_.end();)
	{
		auto& action = *(*iter);
		switch (action.GetStatus())
		{
		case EActionStatus::E_READY:
			action.OnStart();
			SetActionStatus(action, EActionStatus::E_RUNNING);
			++iter;
			break;
		case EActionStatus::E_RUNNING:
			action.OnUpdate();
			++iter;
			break;
		case EActionStatus::E_FINISH:
			action.OnFinish();
			iter = actions_.erase(iter);
			break;
		default:
			break;
		}
	}
}

void SeqActionManager::OnFinish()
{
	actions_.clear();
}

void SeqActionManager::Add(IAction* action)
{
	actions_.push_back(action);
}

void SeqActionManager::Rem(IAction* action)
{
	SetActionStatus(*action, EActionStatus::E_FINISH);
}

NS_RENDER_END