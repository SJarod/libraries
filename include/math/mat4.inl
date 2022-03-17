#include <cassert>

#include "math/float4.hpp"

#include "math/mat4.hpp"

inline const mat4 mat4::zo = { float4::zo, float4::zo, float4::zo, float4::zo };
inline const mat4 mat4::id = {
	1.f, 0.f, 0.f, 0.f,
	0.f, 1.f, 0.f, 0.f,
	0.f, 0.f, 1.f, 0.f,
	0.f, 0.f, 0.f, 1.f
};

inline float4& mat4::operator[](const unsigned int i)
{
	assert(("out of range", i < 4));
	return row[i];
}

inline const float4& mat4::operator[](const unsigned int i) const
{
	assert(("out of range", i < 4));
	return row[i];
}

inline float4 operator*(const mat4& m, const float4& f)
{
	float4 temp = {};

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			temp[i] += m[i][j] * f[j];
		}
	}

	return temp;
}

inline mat4 operator*(const mat4& m1, const mat4& m2)
{
	mat4 temp = {};

				// 0  1  2  3
				// 4  5  6  7
				// 8  9 10 11
				//12 13 14 15
	// 0  1  2  3
	// 4  5  6  7
	// 8  9 10 11
	//12 13 14 15

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				//column
				/*
				temp[i][j] += m1[i][k] * m2.elem[k * 4 + j];
				*/
				//row
				temp[j][i] += m1[k][i] * m2.elem[j * 4 + k];
			}
		}
	}

	return temp;
}