#include <iostream>

#include <chrono>
#include <functional>

#include "utils/threadpool.hpp"

Utils::Task::Task(std::function<void()> fct)
	: task(fct)
{
}

void Utils::Task::doTask()
{
	if (task)
		task();
}

Utils::ThreadPool::ThreadPool(unsigned int nThread)
{
	this->nThread = nThread;

	if (nThread > 0)
		th = new std::thread[nThread];

	running.store(true);

	for (unsigned int i = 0; i < nThread; ++i)
		th[i] = std::thread(std::bind(&ThreadPool::poolRoutine, this, i));
}

Utils::ThreadPool::~ThreadPool()
{
	if (running.load())
		endPool();

	if (th)
		delete[] th;
}

void Utils::ThreadPool::setMultithread(const bool param)
{
	if (tasks.emptyQueue())
		multithread = param;
}

bool& Utils::ThreadPool::getMultithreadParam()
{
	return multithread;
}

unsigned int Utils::ThreadPool::getThreadsNumber() const
{
	return nThread;
}

void Utils::ThreadPool::addTask(std::function<void()> fct)
{
	queueSL.lock();
	tasks.pushBackNode(Task(fct));
	queueSL.unlock();

	if (!multithread)
		work();
 }

void Utils::ThreadPool::removeTask(const int iterator)
{
	//spinlock already locked
	tasks.popFrontNode(iterator);
	queueSL.unlock();
}

void Utils::ThreadPool::work()
{
	//spinlock already locked
	Task t = tasks.frontData();
	removeTask();

	t.doTask();

	auto now = (float)std::chrono::duration_cast<std::chrono::milliseconds>
		(std::chrono::steady_clock::now().time_since_epoch()).count();
	lastTaskTime.store(now);
}

void Utils::ThreadPool::poolRoutine(int id)
{
	while (running.load())
	{
		if (!multithread)
			std::this_thread::sleep_for(std::chrono::milliseconds(10));

		queueSL.lock();

		if (tasks.emptyQueue())
		{
			queueSL.unlock();
			continue;
		}

		//printThreadId(id);
		work();
	}
}

void Utils::ThreadPool::printThreadId(int id)
{
	printSL.lock();
	std::cout << "thread #" << id << std::endl;
	printSL.unlock();
}

void Utils::ThreadPool::endPool()
{
	while (!tasks.emptyQueue())
		std::this_thread::yield();

	running.store(false);

	for (unsigned int i = 0; i < nThread; ++i)
		th[i].join();
}

void Utils::ThreadPool::setStartTime()
{
	startTime = (float)std::chrono::duration_cast<std::chrono::milliseconds>
		(std::chrono::steady_clock::now().time_since_epoch()).count();
}

float Utils::ThreadPool::getLoadingTime()
{
	endTime = (float)std::chrono::duration_cast<std::chrono::milliseconds>
		(std::chrono::steady_clock::now().time_since_epoch()).count();

	return (endTime - startTime) / 1000.f;
}

float Utils::ThreadPool::printLastWorkingTime()
{
	if (lastTaskTime == 0.f)
		return 0.f;

	return (lastTaskTime - startTime) / 1000.f;
}

float Utils::ThreadPool::printLastWorkingTimeOnce()
{
	if (lastTaskTime == 0.f)
		return 0.f;

	float val = (lastTaskTime - startTime) / 1000.f;
	printSL.lock();
	std::cout << "LOADING TIME : " << val << "s" << std::endl;
	printSL.unlock();
	lastTaskTime = 0.f;

	return val;
}