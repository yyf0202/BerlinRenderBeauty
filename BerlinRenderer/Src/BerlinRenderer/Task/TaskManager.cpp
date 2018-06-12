
#include "TaskManager.h"
#include "ThreadPool.h"

NS_RENDER_BEGIN

TaskManager::TaskManager(ThreadPool* threadPool)
	: threadPool_(threadPool)
{
}

void TaskManager::AddTask(ITask* task)
{
	threadPool_->Submit(std::bind(&TaskManager::TaskAdapt, this, task));
}

void TaskManager::Update()
{
	locker_.lock();
	{
		for_each(iter, finishTask_)
		{
			(*iter)->EndTask();
		}
		finishTask_.clear();
	}
	locker_.unlock();
}

void TaskManager::TaskAdapt(ITask* task)
{
	task->BeginTask();
	locker_.lock();
	{
		finishTask_.push_back(task);
	}
	locker_.unlock();
}

NS_RENDER_END