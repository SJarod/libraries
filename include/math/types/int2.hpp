#pragma once

struct int2
{
	union
	{
		struct { int x; int y; };
		int    elem[2];
	};

	/**
	 * Access this vector's elements with [].
	 */
	inline int& operator[](const unsigned int i);

	/**
	 * Access this vector's elements with [].
	 */
	inline const int& operator[](const unsigned int i) const;
};

#include "math/types/int2.inl"