#pragma once

struct float3;

struct mat3
{
	union
	{
		float3	row[3];
		float	elem[9];
	};

	//zero
	static const mat3 zo;
	//identity
	static const mat3 id;

	/**
	 * Access this matrix's row with [].
	 * 
	 * @param i
	 * @return row
	 */
	inline float3& operator[](const unsigned int i);

	/**
	 * Access this matrix's row with [].
	 * 
	 * @param i
	 * @return row
	 */
	inline const float3& operator[](const unsigned int i) const;
};

#include "math/types/mat3.inl"