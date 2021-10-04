#pragma once

#include <thread>
#include <atomic>

#include "utils/utils.hpp"
#include <functional>

namespace Utils
{
	class Task
	{
	private:
		std::function<void()> task;

	public:
		Task() = default;
		Task(std::function<void()> fct);

		void doTask();
	};

	class ThreadPool
	{
	private:
		std::thread*		th = nullptr;
		unsigned int		nThread = 0;	//number of threads
		bool				multithread = true;

		float				startTime = 0.f;
		float				endTime = 0.f;
		std::atomic<float>	lastTaskTime;

		Queue<Task>			tasks;			//shared data
		SpinLock			queueSL;
		SpinLock			printSL;

		std::atomic<bool>	running;		//is routine running?

	public:
		ThreadPool(unsigned int nThread = std::thread::hardware_concurrency());
		~ThreadPool();

		//true : multithread, false : monothread
		void			setMultithread(const bool param);
		bool&			getMultithreadParam();
		unsigned int	getThreadsNumber() const;

		void	addTask(std::function<void()> fct);
		void	removeTask(const int iterator = 0);
		void	work();

		//thread routine
		void	poolRoutine(int id);
		void	printThreadId(int id);

		//join every thread, after end of every task
		void	endPool();

		void	setStartTime();
		//return loading time in seconds
		//user chooses when to show the loading time
		float	getLoadingTime();
		//time when the pool has finished doing every tasks
		float	printLastWorkingTime();
		float	printLastWorkingTimeOnce();
	};
}

using namespace Utils;