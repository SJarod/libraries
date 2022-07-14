#include "mathematics.hpp"

template<typename T>
inline T Math::min(const T& a, const T& b)
{
	return a < b ? a : b;
}

template<typename T>
inline T Math::max(const T& a, const T& b)
{
	return a > b ? a : b;
}

inline float3 Math::min(const float3& a, const float3& b)
{
	return { min(a.x, b.x), min(a.y, b.y), min(a.z, a.z) };
}

inline float3 Math::max(const float3& a, const float3& b)
{
	return { max(a.x, b.x), max(a.y, b.y), max(a.z, a.z) };
}

template<typename T>
inline T Math::clamp(const T& value, const T& mini, const T& maxi)
{
	return max(mini, min(value, maxi));
}

inline float Math::saturate(const float& value)
{
	return max(0.f, min(value, 1.f));
}

template<typename T>
inline T Math::remap(const T val, const T min1, const T max1, const T min2, const T max2)
{
	return min2 + (val - min1) * (max2 - min2) / (max1 - min1);
}

template<typename T>
inline T Math::lerp(const T& from, const T& to, const T& t)
{
	return (1 - t) * from + t * to;
}

inline float3 Math::lerp(const float3& from, const float3& to, const float& t)
{
	return { lerp(from.x, to.x, t),
			 lerp(from.y, to.y, t),
			 lerp(from.z, to.z, t) };
}

inline Quaternion Math::nlerp(const Quaternion& from, const Quaternion& to, const float& t)
{
	float4 v;
	v.x = lerp(from.a, to.a, t);
	v.y = lerp(from.i, to.i, t);
	v.z = lerp(from.j, to.j, t);
	v.w = lerp(from.k, to.k, t);

	v = v.normalized();

	return Quaternion(v.x, v.y, v.z, v.w);
}

inline Quaternion Math::slerp(const Quaternion& from, const Quaternion& to, const float& t)
{
	float cosHalfOmega = Math3::dot(from.vec(), to.vec());

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


inline float Math2::dot(const float2& a, const float2& b)
{
	return a.x * b.x + a.y * b.y;
}

inline float2 Math2::rotate(const float2& v, const float& angle)
{
	float a = angle * Math::Conversion::degrad;
	float x = cosf(a) * v.x - sinf(a) * v.y;
	float y = sinf(a) * v.x + cosf(a) * v.y;

	return { x, y };
}


inline float Math3::dot(const float3& a, const float3& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline float Math3::dot(const float4& a, const float4& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

inline float3 Math3::cross(const float3& a, const float3& b)
{
	float3 v;
	v.x = a.y * b.z - a.z * b.y;
	v.y = a.z * b.x - a.x * b.z;
	v.z = a.x * b.y - a.y * b.x;
	return v;
}

inline mat4 Math3::transpose(const mat4& m)
{
	mat4 t = {
		m.elem[0], m.elem[4],  m.elem[8], m.elem[12],
		m.elem[1], m.elem[5],  m.elem[9], m.elem[13],
		m.elem[2], m.elem[6], m.elem[10], m.elem[14],
		m.elem[3], m.elem[7], m.elem[11], m.elem[15]
	};
	return t;
}

inline mat4 Math3::frustum(const float& left, const float& right, const float& bot, const float& top, const float& near, const float& far)
{
	mat4 frs;
	frs.row[0] = { (2 * near) / (right - left), 0.f, (right + left) / (right - left), 0.f };
	frs.row[1] = { 0.f, (2 * near) / (top - bot), (top + bot) / (top - bot), 0.f };
	frs.row[2] = { 0.f, 0.f, -(far + near) / (far - near), -(2 * far * near) / (far - near) };
	frs.row[3] = { 0.f, 0.f, -1.f, 0.f };
	return frs;
}

inline mat4 Math3::perspective(const float& fovYdeg, const float& aspect, const float& near, const float& far)
{
	float top = near * tanf(fovYdeg * Math::Conversion::degrad * 0.5f);
	float right = top * aspect;

	return frustum(-right, right, -top, top, near, far);
}

inline mat4 Math3::orthographic(const float& left, const float& right, const float& bot, const float& top, const float& near, const float& far)
{
	mat4 orth;
	orth.row[0] = { 2 / (right - left), 0.f, 0.f, -(right + left) / (right - left) };
	orth.row[1] = { 0.f, 2 / (top - bot), 0.f, -(top + bot) / (top - bot) };
	orth.row[2] = { 0.f, 0.f, -2 / (far - near), -(far + near) / (far - near) };
	orth.row[3] = { 0.f, 0.f, 0.f, 1.f };
	return orth;
}

inline mat4 Math3::translateMatrix(const float3& pos)
{
	return mat4{
		1.f, 0.f, 0.f, pos.x,
		0.f, 1.f, 0.f, pos.y,
		0.f, 0.f, 1.f, pos.z,
		0.f, 0.f, 0.f, 1.f,
	};
}

inline mat4 Math3::rotateXMatrix(const float& pitch)
{
	float a = pitch * Math::Conversion::degrad;
	return mat4{
		1.f, 0.f, 0.f, 0.f,
		0.f, cos(a), -sin(a), 0.f,
		0.f, sin(a), cos(a), 0.f,
		0.f, 0.f, 0.f, 1.f,
	};
}

inline mat4 Math3::rotateYMatrix(const float& yaw)
{
	float a = yaw * Math::Conversion::degrad;
	return mat4{
		cos(a), 0.f, sin(a), 0.f,
		0.f, 1.f, 0.f, 0.f,
		-sin(a), 0.f, cos(a), 0.f,
		0.f, 0.f, 0.f, 1.f,
	};
}

inline mat4 Math3::rotateZMatrix(const float& roll)
{
	float a = roll * Math::Conversion::degrad;
	return mat4{
		cos(a), -sin(a), 0.f, 0.f,
		sin(a), cos(a), 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		0.f, 0.f, 0.f, 1.f,
	};
}

inline mat4 Math3::scaleMatrix(const float3& scale)
{
	return mat4{
		scale.x, 0.f, 0.f, 0.f,
		0.f, scale.y, 0.f, 0.f,
		0.f, 0.f, scale.z, 0.f,
		0.f, 0.f, 0.f, 1.f,
	};
}

inline float3 Math3::rotateQ(const float3& v, const float& angle, const float3& axis)
{
	Quaternion q(angle, axis);
	Quaternion qb = q.conjugate();
	Quaternion qv = v.q();

	Quaternion qr = q * qv * qb;	//quaternion after rotation

	return { qr.i, qr.j, qr.k };
}

template <class Q>
inline float3 Math3::rotateQ(const float3& v, const Q& q)
{
	Quaternion qr = q * v.q() * q.conjugate();
	return { qr.i, qr.j, qr.k };
}

template<typename firstQuaternion, typename... quaternionArgs>
inline float3 Math3::rotateQ(const float3& v, const firstQuaternion& q1, const quaternionArgs&... qs)
{
	float3 r = rotateQ(v, q1);
	r = rotateQ(r, qs...);

	return r;
}


inline std::ostream& operator<<(std::ostream& os, const float2& v)
{
	os << "---float2---" << std::endl;
	os << v.x << ", " << v.y;
	return os;
}

inline std::ostream& operator<<(std::ostream& os, const float3& v)
{
	os << "---float3---" << std::endl;
	os << v.x << ", " << v.y << ", " << v.z;
	return os;
}

inline std::ostream& operator<<(std::ostream& os, const float4& v)
{
	os << "---float4---" << std::endl;
	os << v.x << ", " << v.y << ", " << v.z << ", " << v.w;
	return os;
}

inline std::ostream& operator<<(std::ostream& os, const mat3& m)
{
	os << "---mat3---" << std::endl;
	os << m.row[0].x << ", " << m.row[0].y << ", " << m.row[0].z << std::endl;
	os << m.row[1].x << ", " << m.row[1].y << ", " << m.row[1].z << std::endl;
	os << m.row[2].x << ", " << m.row[2].y << ", " << m.row[2].z;

	return os;
}

inline std::ostream& operator<<(std::ostream& os, const mat4& m)
{
	os << "---mat4---" << std::endl;
	os << m.row[0].x << ", " << m.row[0].y << ", " << m.row[0].z << ", " << m.row[0].w << std::endl;
	os << m.row[1].x << ", " << m.row[1].y << ", " << m.row[1].z << ", " << m.row[1].w << std::endl;
	os << m.row[2].x << ", " << m.row[2].y << ", " << m.row[2].z << ", " << m.row[2].w << std::endl;
	os << m.row[3].x << ", " << m.row[3].y << ", " << m.row[3].z << ", " << m.row[3].w;

	return os;
}

template<typename T, uint N>
inline std::ostream& operator<<(std::ostream& os, const vec<T, N>& v)
{
#ifdef RAW_VEC_TEMPLATE_NAME
	os << "---vec<" << typeid(T).name() << ", " << N << ">---" << std::endl;
#else
	os << "---" << typeid(T).name() << N << "---" << std::endl;
#endif

	for (uint i = 0; i < N; ++i)
	{
		os << v.elem[i];
		if (i < N - 1)
			os << ", ";
	}

	return os;
}