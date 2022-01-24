#include "math/math.hpp"
#include "math/quaternion.hpp"

const vec2 vec2::zero	{  0.f,  0.f };
const vec2 vec2::up		{  0.f,  1.f };
const vec2 vec2::down	{  0.f, -1.f };
const vec2 vec2::left	{ -1.f,  0.f };
const vec2 vec2::right	{  1.f,  0.f };

const vec3 vec3::zero		{  0.f,  0.f,  0.f };
const vec3 vec3::up			{  0.f,  1.f,  0.f };
const vec3 vec3::down		{  0.f, -1.f,  0.f };
const vec3 vec3::left		{ -1.f,  0.f,  0.f };
const vec3 vec3::right		{  1.f,  0.f,  0.f };
const vec3 vec3::forward	{  0.f,  0.f, -1.f };
const vec3 vec3::backward	{  0.f,  0.f,  1.f };

const vec4 vec4::zero{ 0.f, 0.f, 0.f, 0.f };

const mat3 mat3::zero		{ vec3::zero, vec3::zero, vec3::zero };
const mat3 mat3::identity	{ vec3::right, vec3::up, vec3::backward };

const mat4 mat4::zero{ vec4::zero, vec4::zero, vec4::zero, vec4::zero };
const mat4 mat4::identity{
	1.f, 0.f, 0.f, 0.f,
	0.f, 1.f, 0.f, 0.f,
	0.f, 0.f, 1.f, 0.f,
	0.f, 0.f, 0.f, 1.f
};

const Quaternion Quaternion::identity{ 1.f, 0.f, 0.f, 0.f };

Quaternion Math::nlerp(const Quaternion& from, const Quaternion& to, const float& t)
{
	vec4 v;
	v.x = lerp(from.a, to.a, t);
	v.y = lerp(from.i, to.i, t);
	v.z = lerp(from.j, to.j, t);
	v.w = lerp(from.k, to.k, t);

	v = v.normalized();

	return Quaternion(v.x, v.y, v.z, v.w);
}

Quaternion Math::slerp(const Quaternion& from, const Quaternion& to, const float& t)
{
	float cosHalfOmega = Math3::dotProduct(from.v4, to.v4);

	Quaternion tto = to;
	if (cosHalfOmega < 0)
	{
		tto = -tto;
		cosHalfOmega *= -1.f;
	}

	if (fabs(cosHalfOmega) >= 1.0f)
	{
		return from;
	}
	else
	{
		float halfOmega = acosf(cosHalfOmega);
		float sinHalfOmega = sqrtf(1.f - cosHalfOmega * cosHalfOmega);

		return from * (sinf((1 - t) * halfOmega) / sinHalfOmega) + tto * (sinf(t * halfOmega) / sinHalfOmega);
	}
}

Quaternion vec3::q() const
{
	Quaternion q = { 0, x, y, z };
	return q;
}

vec3 Math3::crossProduct(const vec3& a, const vec3& b)
{
	vec3 v;
	v.x = a.y * b.z - a.z * b.y;
	v.y = a.z * b.x - a.x * b.z;
	v.z = a.x * b.y - a.y * b.x;
	return v;
}

vec2 Math2::rotate(const vec2& v, const float& angle)
{
	float a = angle * TORAD;
	float x = cosf(a) * v.x - sinf(a) * v.y;
	float y = sinf(a) * v.x + cosf(a) * v.y;

	return { x, y };
}

mat4 Math3::translateMatrix(const vec3& pos)
{
	return mat4{
		1.f, 0.f, 0.f, pos.x,
		0.f, 1.f, 0.f, pos.y,
		0.f, 0.f, 1.f, pos.z,
		0.f, 0.f, 0.f, 1.f,
	};
}

mat4 Math3::rotateXMatrix(const float& pitch)
{
	float a = pitch * TORAD;
	return mat4{
		1.f, 0.f, 0.f, 0.f,
		0.f, cos(a), -sin(a), 0.f,
		0.f, sin(a), cos(a), 0.f,
		0.f, 0.f, 0.f, 1.f,
	};
}

mat4 Math3::rotateYMatrix(const float& yaw)
{
	float a = yaw * TORAD;
	return mat4{
		cos(a), 0.f, sin(a), 0.f,
		0.f, 1.f, 0.f, 0.f,
		-sin(a), 0.f, cos(a), 0.f,
		0.f, 0.f, 0.f, 1.f,
	};
}

mat4 Math3::rotateZMatrix(const float& roll)
{
	float a = roll * TORAD;
	return mat4{
		cos(a), -sin(a), 0.f, 0.f,
		sin(a), cos(a), 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		0.f, 0.f, 0.f, 1.f,
	};
}

mat4 Math3::scaleMatrix(const vec3& scale)
{
	return mat4{
		scale.x, 0.f, 0.f, 0.f,
		0.f, scale.y, 0.f, 0.f,
		0.f, 0.f, scale.z, 0.f,
		0.f, 0.f, 0.f, 1.f,
	};
}

std::ostream& operator<<(std::ostream& os, const vec2& v)
{
	os << "---vec2---" << std::endl;
	os << v.x << ", " << v.y;
	return os;
}

std::ostream& operator<<(std::ostream& os, const vec3& v)
{
	os << "---vec3---" << std::endl;
	os << v.x << ", " << v.y << ", " << v.z;
	return os;
}

std::ostream& operator<<(std::ostream& os, const vec4& v)
{
	os << "---vec4---" << std::endl;
	os << v.x << ", " << v.y << ", " << v.z << ", " << v.w;
	return os;
}

std::ostream& operator<<(std::ostream& os, const mat3& m)
{
	os << "---mat3---" << std::endl;
	os << m.c[0].x << ", " << m.c[0].y << ", " << m.c[0].z << std::endl;
	os << m.c[1].x << ", " << m.c[1].y << ", " << m.c[1].z << std::endl;
	os << m.c[2].x << ", " << m.c[2].y << ", " << m.c[2].z;

	return os;
}

std::ostream& operator<<(std::ostream& os, const mat4& m)
{
	os << "---mat4---" << std::endl;
	os << m.c[0].x << ", " << m.c[0].y << ", " << m.c[0].z << ", " << m.c[0].w << std::endl;
	os << m.c[1].x << ", " << m.c[1].y << ", " << m.c[1].z << ", " << m.c[1].w << std::endl;
	os << m.c[2].x << ", " << m.c[2].y << ", " << m.c[2].z << ", " << m.c[2].w << std::endl;
	os << m.c[3].x << ", " << m.c[3].y << ", " << m.c[3].z << ", " << m.c[3].w;

	return os;
}