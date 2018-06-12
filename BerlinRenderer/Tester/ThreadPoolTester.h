#pragma once

#include <BerlinRenderer/BerlinRenderer.h>

USE_RENDER;

namespace tester
{
	class ThreadPoolTester
	{
	public:
		int total;
		std::mutex locker;

	public:
		static bool Run()
		{
			static int s_sum = 0;

			ThreadPool pool(10);

			auto tster = new ThreadPoolTester();
			auto main = 0;
			for (;;)
			{
				pool.Submit(std::bind(&ThreadPoolTester::Add, tster));
				auto r = std::rand() % 100;
				std::this_thread::sleep_for(std::chrono::milliseconds(r));
				main += r;

				if (r == 30)
				{
					printf("main thread has a big sleep \n");
					std::this_thread::sleep_for(std::chrono::milliseconds(3000));
					tster->locker.lock();
					printf("main thread done task: %d  subthread done task: %d \n", main, tster->total);
					tster->locker.unlock();
				}
			}

			return true;
		}

		void Add()
		{
			auto r = std::rand() % 500;
			std::this_thread::sleep_for(std::chrono::milliseconds(r));
			printf("%d thread run end\n", std::this_thread::get_id());
			locker.lock();
			total += r;
			locker.unlock();
		}
	};
}