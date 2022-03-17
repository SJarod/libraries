#pragma once

#include <thread>
#include <atomic>
#include <functional>

#include "utils/utils.hpp"

namespace Utils
{
	class Task
	{
	private:
		std::function<void()> task;

	public:
		Task() = default;

		/**
		 * Create a task using a function.
		 * 
		 * @param fct
		 */
		Task(std::function<void()> fct);

		/**
		 * Run the function.
		 * 
		 */
		void doTask();
	};

	class ThreadPool
	{
	private:
		std::thread*	th = nullptr;
		//number of threads
		uint			nThread = 0;
		bool			multithread = true;

		float				startTime = 0.f;
		float				endTime = 0.f;
		std::atomic<float>	lastTaskTime;

		//shared date
		Queue<Task>			tasks;
		SpinLock			queueSL;
		SpinLock			printSL;

		//is the routine running?
		std::atomic<bool>	running;

	public:
		/**
		 * Create the thread pool.
		 * Specify the number of threads, the number of threads is by default the maximum that the machine can get.
		 * 
		 * @param nThread
		 */
		ThreadPool(uint nThread = std::thread::hardware_concurrency());

		/**
		 * End the thread pool.
		 * 
		 */
		~ThreadPool();

		/**
		 * Set the pool to function or not.
		 * true : multithread
		 * false : monothread
		 * 
		 * @param param
		 */
		void setMultithread(const bool param);

		/**
		 * Is the pool functionning in multithread?
		 * 
		 * @return 
		 */
		bool& getMultithreadParam();

		/**
		 * Get the number of threads.
		 * 
		 * @return 
		 */
		uint getThreadsNumber() const;

		/**
		 * Add a task to the task queue.
		 * 
		 * @param fct
		 */
		void addTask(std::function<void()> fct);

		/**
		 * Remove a task from the task queue.
		 * 
		 * @param iterator
		 */
		void removeTask(const int iterator = 0);

		/**
		 * Choose a task then do it.
		 * 
		 */
		void work();

		/**
		 * Thread routine.
		 * Main loop function
		 * 
		 * @param id
		 */
		void poolRoutine(int id);

		/**
		 * Print the thread id.
		 * 
		 * @param id
		 */
		void printThreadId(int id);

		/**
		 * Join every threads, after the end of every task.
		 * 
		 */
		void endPool();

		/**
		 * Get the time to store as the thread pool's starting time.
		 * 
		 */
		void setStartTime();

		/**
		 * Return the time between now and the start time.
		 * Equivalent to a loading time.
		 * The user chooses when to show the loading time, do not forget to set the start time.
		 */
		float getLoadingTime();

		/**
		 * Time when the pool has finished doing every tasks.
		 */
		float printLastWorkingTime();

		/**
		 * Print the time when the last task was finished.
		 * 
		 * @return 
		 */
		float printLastWorkingTimeOnce();
	};
}