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

typedef unsigned int uint;

#include <cmath>
#include <cfloat>

#include <iostream>

#include "math/types/float2.hpp"
#include "math/types/float3.hpp"
#include "math/types/float4.hpp"

#include "math/types/vect.hpp"

#include "math/types/mat3.hpp"
#include "math/types/mat4.hpp"

#include "math/types/quaternion.hpp"

namespace Math
{
	/**
	 * Minimal value between a and b.
	 */
	inline float min(const float& a, const float& b);

	/**
	 * Maximal value between a and b.
	 */
	inline float max(const float& a, const float& b);

	/**
	 * Minimal vector between a and b.
	 * 
	 * @return float3 where its elements are the minimums of the corresponding elements between a and b
	 */
	inline float3 min(const float3& a, const float3& b);

	/**
	 * Maximal vector between a and b.
	 *
	 * @return float3 where its elements are the maximums of the corresponding elements between a and b
	 */
	inline float3 max(const float3& a, const float3& b);

	/**
	 * Cap a value for it not to exceed the specified range.
	 * 
	 * @param value
	 * @param minimal step
	 * @param maximal step
	 */
	inline float clamp(const float& value, const float& mini, const float& maxi);

	/**
	 * Clamp between 0 and 1.
	 */
	inline float saturate(const float& value);

	/**
	 * Remap a value.
	 * Transform a value from a range for it to fit into a new range.
	 * 
	 * @param value
	 * @param first minimal step
	 * @param first maximal step
	 * @param second minimal step
	 * @param second maximal step
	 */
	inline int remap(const int val, const int min1, const int max1, const int min2, const int max2);

	/**
	 * Linear interpolation from a specified value to another according to a specified time.
	 */
	inline float lerp(const float& from, const float& to, const float& t);

	/**
	 * Linear interpolation from a specified vector to another according to a specified time.
	 */
	inline float3 lerp(const float3& from, const float3& to, const float& t);

	/**
	 * Normalized linear interpolation used in rotation.
	 */
	inline Quaternion nlerp(const Quaternion& from, const Quaternion& to, const float& t);

	/**
	 * Spherical linear interpolation used in rotation.
	 */
	inline Quaternion slerp(const Quaternion& from, const Quaternion& to, const float& t);
}

namespace Math2
{
	/**
	 * Dot product between 2 vectors.
	 */
	inline float dot(const float2& a, const float2& b);

	/**
	 * Rotate a vector.
	 * 
	 * @param float2
	 * @param angle in degrees
	 */
	inline float2 rotate(const float2& v, const float& angle);
}

namespace Math3
{
	/**
	 * Dot product between 2 vector3.
	 */
	inline float dot(const float3& a, const float3& b);

	/**
	 * Dot product between 2 vector4.
	 */
	inline float dot(const float4& a, const float4& b);

	/**
	 * Cross product between 2 vector3.
	 */
	inline float3 cross(const float3& a, const float3& b);

	/**
	 * Transpose of a matrix.
	 */
	inline mat4 transpose(const mat4& m);

	/**
	 * Frustum matrix.
	 */
	inline mat4 frustum(const float& left, const float& right, const float& bot, const float& top, const float& near, const float& far);

	/**
	 * Perspective matrix using frustum matrix.
	 */
	inline mat4 perspective(const float& fovYdeg, const float& aspect, const float& near, const float& far);

	/**
	 * Orthographic frustum matrix.
	 */
	inline mat4 orthographic(const float& left, const float& right, const float& bot, const float& top, const float& near, const float& far);

	/**
	 * Translation matrix.
	 */
	inline mat4 translateMatrix(const float3& pos);

	/**
	 * Rotation matrix based on Euler's rotation.
	 * 
	 * @param angle in degrees
	 */
	inline mat4 rotateXMatrix(const float& pitch);

	/**
	 * Rotation matrix based on Euler's rotation.
	 * 
	 * @param angle in degrees
	 */
	inline mat4 rotateYMatrix(const float& yaw);

	/**
	 * Rotation matrix based on Euler's rotation.
	 * 
	 * @param angle in degrees
	 */
	inline mat4 rotateZMatrix(const float& roll);

	/**
	 * Scale matrix.
	 */
	inline mat4 scaleMatrix(const float3& scale);

	/**
	 * Rotate a vector3 using quaternion calculation.
	 * 
	 * @param vector3
	 * @param angle in degrees
	 * @param rotation axis
	 */
	inline float3 rotateQ(const float3& v, const float& angle, const float3& axis);

	/**
	 * Rotate a vector3 using a quaternion.
	 * This function only accepts a quaternion in its template slot.
	 */
	template <class Q>
	inline float3 rotateQ(const float3& v, const Q& q);

	/**
	 * Rotate a vector3 using a certain number of quaternions.
	 * The rotations are made in the same order than the order of the arguments.
	 */
	template <typename firstQuaternion, typename... quaternionArgs>
	inline float3 rotateQ(const float3& v, const firstQuaternion& q1, const quaternionArgs&... qs);
}

/**
 * Display a float2 in the console.
 */
inline std::ostream& operator<<(std::ostream& os, const float2& v);

/**
 * Display a float3 in the console.
 */
inline std::ostream& operator<<(std::ostream& os, const float3& v);

/**
 * Display a float4 in the console.
 */
inline std::ostream& operator<<(std::ostream& os, const float4& v);

/**
 * Display a mat3 in the console.
 */
inline std::ostream& operator<<(std::ostream& os, const mat3& m);

/**
 * Display a mat4 in the console.
 */
inline std::ostream& operator<<(std::ostream& os, const mat4& m);

#include "math/math.inl"