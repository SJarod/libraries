#pragma once

typedef unsigned int uint;

union vec2;
union vec3;
union Quaternion;

union int2
{
	int e[2];
};

union int3
{
	int e[3];
};

union uint2
{
	uint e[2];
};

union uint3
{
	uint e[3];
};

union vec2
{
	float  e[2];
	struct { float x; float y; };

	static const vec2 zero;
	static const vec2 up;
	static const vec2 down;
	static const vec2 left;
	static const vec2 right;

	inline float sqrMag() const;
	inline float mag() const;
	inline vec2	 normalized() const;
};

union vec3
{
	float  e[3];
	struct { float x; float y; float z; };
	struct { float i; float j; float k; };
	vec2   xy;

	static const vec3 zero;
	static const vec3 up;
	static const vec3 down;
	static const vec3 left;
	static const vec3 right;
	static const vec3 forward;
	static const vec3 backward;

	//get vector's quaternion
	Quaternion q() const;

	inline float sqrMag() const;
	inline float mag() const;
	inline vec3	 normalized() const;
};

union vec4
{
	float  e[4];
	struct { float x; float y; float z; float w; };
	struct { float r; float g; float b; float a; };
	vec3   xyz;
	vec3   rgb;

	static const vec4 zero;

	inline float sqrMag() const;
	inline float mag() const;
	inline vec4	 normalized() const;
};

typedef vec2 float2;
typedef vec3 float3;
typedef vec4 float4;

union mat3
{
	vec3	c[3];
	float	e[9];

	static const mat3 zero;
	static const mat3 identity;
};

union mat4
{
	vec4	c[4];
	float	e[16];

	static const mat4 zero;
	static const mat4 identity;
};

union Quaternion
{
	//q = a + bi + cj + dk
	struct { float a; float i; float j; float k; };
	vec4   v4;	//show quaternion as a vec4

	static const Quaternion identity;

	Quaternion() = default;
	Quaternion(const float& a, const float& i, const float& j, const float& k);	//create simple quaternion
	Quaternion(const float& angle, const vec3& v);								//create rotation quaternion, angle in degrees

	inline Quaternion	conjugate() const;
	mat4				m4() const; //get quaternion as mat4
};