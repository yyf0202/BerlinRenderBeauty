#pragma once

#include <BerlinRenderer/Base/Config.h>

#include <atomic>
#include <thread>
#include <mutex>

NS_RENDER_BEGIN

class ThreadPool
{
public:
	ThreadPool(uint32_t threadCount);
	~ThreadPool();

	void Submit(std::function<void()> task);
private:
	void WorkerThread();

private:
	std::mutex locker_;
	std::atomic_bool done_;
	queue_t<std::function<void()> > work_queue_;
	vector_t<std::thread> threads_;
};

NS_RENDER_END