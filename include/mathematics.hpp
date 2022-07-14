#pragma once

//typedef float as vec (float2 becomes vec2)
#define FLOAT_AS_VEC

//pi
//https://www.angio.net/pi/bigpi.cgi

//precision calculator
//https://www.mathsisfun.com/calculator-precision.html

//The constant values have a 50 digits precision.
#if false
#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288419716939937510f
#endif
// 2 * pi
#ifndef M_TAU
#define M_TAU 6.28318530717958647692528676655900576839433879875021f
#endif
// pi / 180
#ifndef TORAD
#define TORAD 0.01745329251994329576923690768488612713442871888541f
#endif
// 180 / pi
#ifndef TODEG
#define TODEG 57.29577951308232087679815481410517033240547246656432f
#endif
#endif

typedef unsigned int uint;

#include <cmath>
#include <cfloat>

#include <iostream>

namespace Math
{
	struct Constant
	{
		static inline const double pi = 3.14159265358979323846264338327950288419716939937510;
		// 2 * pi
		static inline const double tau = 6.28318530717958647692528676655900576839433879875021;
		static inline const double e = 2.71828182845904523536028747135266249775724709369995;
	};

	struct Conversion
	{
		// pi / 180
		static inline const double degrad = 0.01745329251994329576923690768488612713442871888541;
		// 180 / pi
		static inline const double raddeg = 57.29577951308232087679815481410517033240547246656432;
	};
}

#include "types/float2.hpp"
#include "types/float3.hpp"
#include "types/float4.hpp"

#include "types/vect.hpp"

#include "types/mat3.hpp"
#include "types/mat4.hpp"

#include "types/quaternion.hpp"

namespace Math
{
	/**
	 * Minimal value between a and b.
	 */
	template<typename T>
	inline T min(const T& a, const T& b);

	/**
	 * Maximal value between a and b.
	 */
	template<typename T>
	inline T max(const T& a, const T& b);

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
	template<typename T>
	inline T clamp(const T& value, const T& mini, const T& maxi);

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
	template<typename T>
	inline T remap(const T val, const T min1, const T max1, const T min2, const T max2);

	/**
	 * Linear interpolation from a specified value to another according to a specified time.
	 */
	template<typename T>
	inline T lerp(const T& from, const T& to, const T& t);

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

/**
 * Display a vec<T, N> in the console.
 * Some custom types are strangely displayed.
 * If the type T cannot be printed in an ostream, this operator cannot be called.
 */
template<typename T, uint N>
inline std::ostream& operator<<(std::ostream& os, const vec<T, N>& v);

#include "mathematics.inl"