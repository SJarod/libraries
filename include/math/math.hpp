#pragma once

#define FLOAT_AS_VEC

#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288419716939937510f
#endif
// 2 * pi
#ifndef M_TAU
#define M_TAU 6.28318530717958647692528676655900576839433879875020f
#endif
// pi / 180
#ifndef TORAD
#define TORAD 0.017453292519943295769236907684886127134428718885417f
#endif
// 180 / pi
#ifndef TODEG
#define TODEG 57.295779513082320876798154814105170332405472466564f
#endif

#include <cmath>
#include <cfloat>

#include <iostream>

#include "math/types/int2.hpp"
#include "math/types/int3.hpp"

#include "math/types/uint2.hpp"
#include "math/types/uint3.hpp"

#include "math/types/float2.hpp"
#include "math/types/float3.hpp"
#include "math/types/float4.hpp"

#include "math/types/vec.hpp"

#include "math/types/mat3.hpp"
#include "math/types/mat4.hpp"

#include "math/types/quaternion.hpp"

namespace Math
{
	inline float	min(const float& a, const float& b);
	inline float	max(const float& a, const float& b);
	inline float3	min(const float3& a, const float3& b);
	inline float3	max(const float3& a, const float3& b);

	inline float	clamp(const float& value, const float& mini, const float& maxi);
	inline float	saturate(const float& value);

	inline int		remap(const int val, const int min1, const int max1, const int min2, const int max2);

	inline float		lerp(const float& from, const float& to, const float& t);
	inline float3		lerp(const float3& from, const float3& to, const float& t);
	inline Quaternion	nlerp(const Quaternion& from, const Quaternion& to, const float& t);
	inline Quaternion	slerp(const Quaternion& from, const Quaternion& to, const float& t);
}

namespace Math2
{
	inline float dot(const float2& a, const float2& b);

	//angle in degrees
	inline float2 rotate(const float2& v, const float& angle);
}

namespace Math3
{
	inline float	dot(const float3& a, const float3& b);
	inline float	dot(const float4& a, const float4& b);
	inline float3	cross(const float3& a, const float3& b);

	inline mat4 transpose(const mat4& m);

	inline mat4 frustum(const float& left, const float& right, const float& bot, const float& top, const float& near, const float& far);
	inline mat4 perspective(const float& fovYdeg, const float& aspect, const float& near, const float& far);
	inline mat4 orthographic(const float& left, const float& right, const float& bot, const float& top, const float& near, const float& far);

	inline mat4 translateMatrix(const float3& pos);

	//euler rotation
	inline mat4 rotateXMatrix(const float& pitch);		//angle in degrees
	inline mat4 rotateYMatrix(const float& yaw);		//angle in degrees
	inline mat4 rotateZMatrix(const float& roll);		//angle in degrees

	inline mat4 scaleMatrix(const float3& scale);

	//quaternion rotation
	//angle in degrees
	inline float3 rotateQ(const float3& v, const float& angle, const float3& axis);

	//only accepts Quaternions
	template <class Q>
	inline float3 rotateQ(const float3& v, const Q& q);
	//multiple rotation in the order of arguments
	template <typename firstQuaternion, typename... quaternionArgs>
	inline float3 rotateQ(const float3& v, const firstQuaternion& q1, const quaternionArgs&... qs);
}

inline std::ostream& operator<<(std::ostream& os, const float2& v);
inline std::ostream& operator<<(std::ostream& os, const float3& v);
inline std::ostream& operator<<(std::ostream& os, const float4& v);
inline std::ostream& operator<<(std::ostream& os, const mat3& m);
inline std::ostream& operator<<(std::ostream& os, const mat4& m);

#include "math/math.inl"