#pragma once

#include <cassert>

template<typename T, int N>
struct vec
{
	union
	{
		T elem[N];
	};

	inline vec<T, N>() = default;

	/**
	 * Create a vector setting all of its value to the specified value.
	 *
	 * @param t
	 */
	inline vec<T, N>(const T& t);

	/**
	 * Get the square magnitude of this vector.
	 *
	 * @return
	 */
	inline float sqrMag() const;

	/**
	 * Get the magnitude of this vector.
	 *
	 * @return
	 */
	inline float mag() const;

	/**
	 * Get this vector with normalized magnitude.
	 *
	 * @return
	 */
	inline vec<T, N> normalized() const;

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
inline vec<T, N>::vec(const T& t)
{
	for (int i = 0; i < N; ++i)
	{
		elem[i] = t;
	}
}

template<typename T, int N>
inline float vec<T, N>::sqrMag() const
{
	float m = 0.f;
	for (int i = 0; i < N; ++i)
	{
		m += (float)elem[i] * (float)elem[i];
	}

	return m;
}

template<typename T, int N>
inline float vec<T, N>::mag() const
{
	return sqrtf(sqrMag());
}

template<typename T, int N>
inline vec<T, N> vec<T, N>::normalized() const
{
	float m = mag();
	if (m == 0.f)
		return *this;

	vec<T, N> v;
	for (int i = 0; i < N; ++i)
	{
		v[i] = (float)elem[i] / m;
	}

	return v;
}

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