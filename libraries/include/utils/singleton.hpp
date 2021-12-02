#pragma once

#include "memleaks.hpp"

namespace Utils
{
	/*
	Creating a Singleton class
	--------------------------

	class MySingleton : public Singleton<MySingleton>
	{
		friend class Singleton<MySingleton>;

	private:
		MySingleton() {}
	};

	--------------------------
	Don't forget to call end at the end of program to destory the instance.
	*/

	template<class T>
	class Singleton
	{
	private:
		static T* instance;

	public:
		static inline T* getInstance();

		//destroys singleton instance
		static void end();

		//cannot create any Singleton object
		void operator=(const Singleton& s) = delete;
	};
}

using namespace Utils;

template<class T>
T* Utils::Singleton<T>::instance = new T;

template<class T>
inline T* Utils::Singleton<T>::getInstance()
{
	return instance;
}

template<class T>
inline void Utils::Singleton<T>::end()
{
	delete instance;
}