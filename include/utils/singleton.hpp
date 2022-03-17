#pragma once

#include "memleaks.hpp"

namespace Utils
{
	/**
	 * Creating a Singleton class.
	 * ---------------------------
	 * 
	 * @code
	 *	class MySingleton : public Singleton<MySingleton>
	 *	{
	 *		friend class Singleton<MySingleton>;
	 *	
	 *	private:
	 *		MySingleton() {}
	 *	};
	 * @endcode
	 * 
	 * ---------------------------
	 * Don't forget to call destroy() at the end of program to destory the instance.
	 */
	template<class T>
	class Singleton
	{
	private:
		static T* instance;

	public:
		/**
		 * Get the unique instance.
		 * 
		 * @return 
		 */
		static inline T* getInstance();

		/**
		 * Destroy the singleton instance.
		 * Call this function at the end of program.
		 * 
		 */
		static void destroy();

		/**
		 * Cannot create any singleton object.
		 * 
		 * @param s
		 */
		void operator=(const Singleton& s) = delete;
	};
}

template<class T>
T* Utils::Singleton<T>::instance = new T;

template<class T>
inline T* Utils::Singleton<T>::getInstance()
{
	return instance;
}

template<class T>
inline void Utils::Singleton<T>::destroy()
{
	delete instance;
}