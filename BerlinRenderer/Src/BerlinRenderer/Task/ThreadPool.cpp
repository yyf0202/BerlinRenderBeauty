
#include "ThreadPool.h"

NS_RENDER_BEGIN

ThreadPool::ThreadPool(uint32_t threadCount)
{
	done_.store(false);
	for (uint32_t i = 0; i < threadCount; ++i)
	{
		threads_.push_back(std::thread(&ThreadPool::WorkerThread, this));
	}
}

ThreadPool::~ThreadPool()
{
	done_ = true;
}

void ThreadPool::Submit(std::function<void()> task)
{
	work_queue_.push(task);
}

void ThreadPool::WorkerThread()
{
	while (!done_)
	{
		std::function<void()> task = nullptr;
		locker_.lock(); // use unlock queue instead of
		{
			if (!work_queue_.empty())
			{
				task = work_queue_.front();
				work_queue_.pop();
			}
		}
		locker_.unlock();
		if (task != nullptr)
		{
			task();
		}
		else
		{
			//std::this_thread::yield();
			// TODO:
			std::this_thread::sleep_for(std::chrono::milliseconds(16));
		}
	}
}

NS_RENDER_END