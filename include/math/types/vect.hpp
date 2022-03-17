#pragma once

#include <cassert>

template<typename T, int N>
struct vec
{
	T elem[N];

	/**
	 * Access this vector's elements with [].
	 * 
	 * @param i
	 * @return 
	 */
	inline T& operator[](const uint i);

	/**
	 * Access this vector's elements with [].
	 * 
	 * @param i
	 * @return 
	 */
	inline const T& operator[](const uint i) const;
};

template<typename T, int N>
inline T& vec<T, N>::operator[](const uint i)
{
	assert(("out of range", i < N));
	return elem[i];
}

template<typename T, int N>
inline const T& vec<T, N>::operator[](const uint i) const
{
	assert(("out of range", i < N));
	return elem[i];
}