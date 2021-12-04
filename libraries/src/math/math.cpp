#include "math/math.hpp"
#include "math/quaternion.hpp"

Quaternion Core::Math::vec3::q() const
{
	Quaternion q = { 0, x, y, z };
	return q;
}

vec3 Core::Math::crossProduct(const vec3& a, const vec3& b)
{
	vec3 v;
	v.x = a.y * b.z - a.z * b.y;
	v.y = a.z * b.x - a.x * b.z;
	v.z = a.x * b.y - a.y * b.x;
	return v;
}

vec2 Core::Math::vec2Rotation(const vec2& v, const float& angle)
{
	float a = angle * TORAD;
	float x = cosf(a) * v.x - sinf(a) * v.y;
	float y = sinf(a) * v.x + cosf(a) * v.y;

	return { x, y };
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
	float a = pitch * TORAD;
	return mat4{
		1.f, 0.f, 0.f, 0.f,
		0.f, cos(a), -sin(a), 0.f,
		0.f, sin(a), cos(a), 0.f,
		0.f, 0.f, 0.f, 1.f,
	};
}

mat4 Core::Math::rotateYMatrix(const float& yaw)
{
	float a = yaw * TORAD;
	return mat4{
		cos(a), 0.f, sin(a), 0.f,
		0.f, 1.f, 0.f, 0.f,
		-sin(a), 0.f, cos(a), 0.f,
		0.f, 0.f, 0.f, 1.f,
	};
}

mat4 Core::Math::rotateZMatrix(const float& roll)
{
	float a = roll * TORAD;
	return mat4{
		cos(a), -sin(a), 0.f, 0.f,
		sin(a), cos(a), 0.f, 0.f,
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

Core::Math::vec2::operator std::string () const
{
	std::string str = "---vec2---\n" + std::to_string(x) + ", " + std::to_string(y);
	return str;
}

Core::Math::vec3::operator std::string () const
{
	std::string str = "---vec3---\n" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
	return str;
}

Core::Math::vec4::operator std::string () const
{
	std::string str = "---vec4---\n" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w);
	return str;
}

Core::Math::mat3::operator std::string () const
{
	std::string str = "---mat3---\n";
	str += std::to_string(c[0].x) + ", " + std::to_string(c[0].y) + ", " + std::to_string(c[0].z) + "\n";
	str += std::to_string(c[1].x) + ", " + std::to_string(c[1].y) + ", " + std::to_string(c[1].z) + "\n";
	str += std::to_string(c[2].x) + ", " + std::to_string(c[2].y) + ", " + std::to_string(c[2].z);

	return str;
}

Core::Math::mat4::operator std::string () const
{
	std::string str = "---mat4---\n";
	str += std::to_string(c[0].x) + ", " + std::to_string(c[0].y) + ", " + std::to_string(c[0].z) + ", " + std::to_string(c[0].w) + "\n";
	str += std::to_string(c[1].x) + ", " + std::to_string(c[1].y) + ", " + std::to_string(c[1].z) + ", " + std::to_string(c[1].w) + "\n";
	str += std::to_string(c[2].x) + ", " + std::to_string(c[2].y) + ", " + std::to_string(c[2].z) + ", " + std::to_string(c[2].w) + "\n";
	str += std::to_string(c[3].x) + ", " + std::to_string(c[3].y) + ", " + std::to_string(c[3].z) + ", " + std::to_string(c[3].w);

	return str;
}