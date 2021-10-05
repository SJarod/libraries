#pragma once

#include "math/math.hpp"

namespace Core
{
	namespace Math
	{
		union Quaternion
		{
			struct	{ float a; float i; float j; float k; };
			vec4	v4;	//show quaternion as a vec4

			Quaternion() = default;
			Quaternion(const float& a, const float& i, const float& j, const float& k);	//create simple quaternion
			Quaternion(const float& angle, const vec3& v);								//create rotation quaternion, angle in degrees

			Quaternion conjugate() const;

			Quaternion operator*(const Quaternion& q) const;
		};

		//quaternion rotation
		//angle in degrees
		vec3 rotateQ(const vec3& v, const float& angle, const vec3& axis);
		vec3 rotateQ(const vec3& v, const Quaternion& q);
	}
}

using namespace Core::Math;