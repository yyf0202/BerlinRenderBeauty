#pragma once

#include <BerlinRenderer/Base/Config.h>

#include <memory>
#include <atomic>
#include <thread>

NS_RENDER_BEGIN

class ThreadPool
{
	/*std::atomic_bool done;
	thread_safe_queue<std::function<void()> > work_queue;
	std::vector<std::thread> threads;
	join_threads joiner;

	void worker_thread()
	{
		while (!done)
		{
			std::function<void()> task;
			if (work_queue.try_pop(task))
			{
				task();
			}
			else
			{
				std::this_thread::yield();
			}
		}
	}
public:
	ThreadPool() :
		joiner(threads)
	{
		done.store(false);
		unsigned const thread_count = std::thread::hardware_concurrency();
		try
		{
			for (unsigned i = 0; i<thread_count; ++i)
			{
				threads.push_back(
					std::thread(&ThreadPool::worker_thread, this));
			}
		}
		catch (...)
		{
			done = true;
			throw;
		}
	}

	~ThreadPool()
	{
		done = true;
	}

	template<typename FunctionType>
	void submit(FunctionType f)
	{
		work_queue.push(std::function<void()>(f));
	}*/
};

NS_RENDER_END