inline Core::Math::float2::operator vec2() const
{
	return vec2{ e[0], e[1] };
}

inline Core::Math::float3::operator vec3() const
{
	return vec3{ e[0], e[1], e[2] };
}

inline Core::Math::vec2::operator float2() const
{
	return float2{ x, y };
}

inline Core::Math::vec3::operator float3() const
{
	return float3{ x, y, z };
}

inline float Core::Math::vec3::sqrMag() const
{
	return x * x + y * y + z * z;
}

inline float Core::Math::vec3::mag() const
{
	return sqrtf(sqrMag());
}

inline vec3 Core::Math::vec3::normalized() const
{
	return (*this) / mag();
}

inline mat3 Core::Math::identity3()
{
	mat3 m;
	m.c[0] = { 1.f, 0.f, 0.f };
	m.c[1] = { 0.f, 1.f, 0.f };
	m.c[2] = { 0.f, 0.f, 1.f };
	return m;
}

inline mat4 Core::Math::identity4()
{
	mat4 m;
	m.c[0] = { 1.f, 0.f, 0.f, 0.f };
	m.c[1] = { 0.f, 1.f, 0.f, 0.f };
	m.c[2] = { 0.f, 0.f, 1.f, 0.f };
	m.c[3] = { 0.f, 0.f, 0.f, 1.f };
	return m;
}

inline float Core::Math::min(const float& a, const float& b)
{
	return a < b ? a : b;
}

inline float Core::Math::max(const float& a, const float& b)
{
	return a > b ? a : b;
}

inline vec3 Core::Math::min(const vec3& a, const vec3& b)
{
	return { min(a.x, b.x), min(a.y, b.y), min(a.z, a.z) };
}

inline vec3 Core::Math::max(const vec3& a, const vec3& b)
{
	return { max(a.x, b.x), max(a.y, b.y), max(a.z, a.z) };
}

inline void Core::Math::clamp(float& value, const float& mini, const float& maxi)
{
	value = max(mini, min(value, maxi));
}

inline float Core::Math::dotProduct(const vec2& a, const vec2& b)
{
	return a.x * b.x + a.y * b.y;
}

inline float Core::Math::dotProduct(const vec3& a, const vec3& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline vec2 Core::Math::operator+(const vec2& a, const vec2& b)
{
	return { a.x + b.x, a.y + b.y };
}

vec2 Core::Math::operator-(const vec2& a, const vec2& b)
{
	return { a.x - b.x, a.y - b.y };
}

inline vec2 Core::Math::operator*(const float& a, const vec2& v)
{
	return { a * v.x, a * v.y };
}

inline vec3 Core::Math::operator-(const vec3& v)
{
	return { -v.x, -v.y, -v.z };
}

inline vec3 Core::Math::operator-(const vec3& a, const vec3& b)
{
	return { a.x - b.x, a.y - b.y, a.z - b.z };
}

inline vec3 Core::Math::operator*(const float& a, const vec3& v)
{
	return { a * v.x, a * v.y, a * v.z };
}

inline vec3 Core::Math::operator/(const vec3& v, const float a)
{
	if (a == 0)
		return v;

	return { v.x / a, v.y / a, v.z / a };
}

inline void Core::Math::operator+=(vec3& a, const vec3& b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
}

inline vec4 Core::Math::operator*(const mat4& m, const vec4& v)
{
	vec4 temp = {};

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			temp.e[i] += m.c[i].e[j] * v.e[j];
		}
	}

	return temp;
}

inline mat4 Core::Math::operator*(const mat4& m, const mat4& m2)
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
				temp.c[i].e[j] += m.c[i].e[k] * m2.e[k * 4 + j];
			}
		}
	}

	return temp;
}