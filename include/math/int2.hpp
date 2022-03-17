#pragma once

struct int2
{
	union
	{
		struct { int x; int y; };
		int    elem[2];
	};

	/**
	 * Access int2 elements.
	 */
	inline int& operator[](const unsigned int i);

	/**
	 * Access int2 elements.
	 */
	inline const int& operator[](const unsigned int i) const;
};

#include "math/int2.inl"