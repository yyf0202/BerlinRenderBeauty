#pragma once

#include <BerlinRenderer/Base/Config.h>

#include "ITask.h"

NS_RENDER_BEGIN

class ThreadPool;

class TaskManager
{
public:
	TaskManager(ThreadPool* threadPool);

	void AddTask(ITask* task);

	void Update();

private:
	void TaskAdapt(ITask* task);

private:
	mutex_t locker_;
	vector_t<ITask*> finishTask_;
	ThreadPool* threadPool_ = nullptr;
};

NS_RENDER_END