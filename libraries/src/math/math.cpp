#include "math/math.hpp"
#include "math/quaternion.hpp"

#include <iostream>

mat3 Core::Math::identity3()
{
	mat3 m;
	m.c[0] = { 1.f, 0.f, 0.f };
	m.c[1] = { 0.f, 1.f, 0.f };
	m.c[2] = { 0.f, 0.f, 1.f };
	return m;
}

mat4 Core::Math::identity4()
{
	mat4 m;
	m.c[0] = { 1.f, 0.f, 0.f, 0.f };
	m.c[1] = { 0.f, 1.f, 0.f, 0.f };
	m.c[2] = { 0.f, 0.f, 1.f, 0.f };
	m.c[3] = { 0.f, 0.f, 0.f, 1.f };
	return m;
}

float Core::Math::min(const float& a, const float& b)
{
	return a < b ? a : b;
}

float Core::Math::max(const float& a, const float& b)
{
	return a > b ? a : b;
}

void Core::Math::clamp(float& value, const float& mini, const float& maxi)
{
	value = max(mini, min(value, maxi));
}

float Core::Math::dotProduct(vec3 a, vec3 b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

vec3 Core::Math::crossProduct(vec3 a, vec3 b)
{
	vec3 v;
	v.x = a.y * b.z - a.z * b.y;
	v.y = a.z * b.x - a.x * b.z;
	v.z = a.x * b.y - a.y * b.x;
	return v;
}

mat4 Core::Math::translateMatrix(const vec3& pos)
{
	return mat4{
		1.f, 0.f, 0.f, pos.x,
		0.f, 1.f, 0.f, pos.y,
		0.f, 0.f, 1.f, pos.z,
		0.f, 0.f, 0.f, 1.f,
	};
}

mat4 Core::Math::rotateXMatrix(const float& pitch)
{
	return mat4{
		1.f, 0.f, 0.f, 0.f,
		0.f, cos(pitch), -sin(pitch), 0.f,
		0.f, sin(pitch), cos(pitch), 0.f,
		0.f, 0.f, 0.f, 1.f,
	};
}

mat4 Core::Math::rotateYMatrix(const float& yaw)
{
	return mat4{
		cos(yaw), 0.f, sin(yaw), 0.f,
		0.f, 1.f, 0.f, 0.f,
		-sin(yaw), 0.f, cos(yaw), 0.f,
		0.f, 0.f, 0.f, 1.f,
	};
}

mat4 Core::Math::rotateZMatrix(const float& roll)
{
	return mat4{
		cos(roll), -sin(roll), 0.f, 0.f,
		sin(roll), cos(roll), 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		0.f, 0.f, 0.f, 1.f,
	};
}

mat4 Core::Math::scaleMatrix(const vec3& scale)
{
	return mat4{
		scale.x, 0.f, 0.f, 0.f,
		0.f, scale.y, 0.f, 0.f,
		0.f, 0.f, scale.z, 0.f,
		0.f, 0.f, 0.f, 1.f,
	};
}

void Core::Math::vec2::print()
{
	std::cout << "---vec2---" << std::endl;
	std::cout << x << ", " << y << std::endl;
}

Quaternion Core::Math::vec3::q()
{
	Quaternion q(0, *this);
	return q;
}

void Core::Math::vec3::print()
{
	std::cout << "---vec3---" << std::endl;
	std::cout << x << ", " << y << ", " << z << std::endl;
}

void Core::Math::vec4::print()
{
	std::cout << "---vec4---" << std::endl;
	std::cout << x << ", " << y << ", " << z << ", " << w << std::endl;
}

void Core::Math::mat3::print()
{
	std::cout << "---mat3---" << std::endl;
	std::cout << c[0].x << ", " << c[0].y << ", " << c[0].z << std::endl;
	std::cout << c[1].x << ", " << c[1].y << ", " << c[1].z << std::endl;
	std::cout << c[2].x << ", " << c[2].y << ", " << c[2].z << std::endl;
}

void Core::Math::mat4::print()
{
	std::cout << "---mat4---" << std::endl;
	std::cout << c[0].x << ", " << c[0].y << ", " << c[0].z << ", " << c[0].w << std::endl;
	std::cout << c[1].x << ", " << c[1].y << ", " << c[1].z << ", " << c[1].w << std::endl;
	std::cout << c[2].x << ", " << c[2].y << ", " << c[2].z << ", " << c[2].w << std::endl;
	std::cout << c[3].x << ", " << c[3].y << ", " << c[3].z << ", " << c[3].w << std::endl;
}