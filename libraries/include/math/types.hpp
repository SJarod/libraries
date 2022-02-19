#pragma once

typedef unsigned int uint;

union Quaternion;

union int2
{
	struct { int x; int y; };
	int    elem[2];

	inline int& operator[](const unsigned int i);
	inline const int& operator[](const unsigned int i) const;
};

union int3
{
	struct { int x; int y; int z; };
	int    elem[3];

	inline int& operator[](const unsigned int i);
	inline const int& operator[](const unsigned int i) const;
};

union uint2
{
	struct { uint x; uint y; };
	uint   elem[2];

	inline uint& operator[](const unsigned int i);
	inline const uint& operator[](const unsigned int i) const;
};

union uint3
{
	struct { uint x; uint y; uint z; };
	uint   elem[3];

	inline uint& operator[](const unsigned int i);
	inline const uint& operator[](const unsigned int i) const;
};

union vec2
{
	struct { float x; float y; };
	float  elem[2];

	inline float& operator[](const unsigned int i);
	inline const float& operator[](const unsigned int i) const;

	//zero
	static const vec2 zo;
	//up
	static const vec2 up;
	//down
	static const vec2 dn;
	//left
	static const vec2 le;
	//right
	static const vec2 ri;

	inline float sqrMag() const;
	inline float mag() const;
	inline vec2	 normalized() const;
};

union vec3
{
	struct { float x; float y; float z; };
	struct { float i; float j; float k; };
	vec2   xy;
	float  elem[3];

	inline float& operator[](const unsigned int i);
	inline const float& operator[](const unsigned int i) const;
	
	//zero
	static const vec3 zo;
	//up
	static const vec3 up;
	//down
	static const vec3 dn;
	//left
	static const vec3 le;
	//right
	static const vec3 ri;
	//forward
	static const vec3 fw;
	//backward
	static const vec3 bw;

	//get vector's quaternion
	Quaternion q() const;

	inline float sqrMag() const;
	inline float mag() const;
	inline vec3	 normalized() const;
};

union vec4
{
	struct { float x; float y; float z; float w; };
	struct { float r; float g; float b; float a; };
	vec3   xyz;
	vec3   rgb;
	float  elem[4];

	inline float& operator[](const unsigned int i);
	inline const float& operator[](const unsigned int i) const;

	//zero
	static const vec4 zo;

	inline float sqrMag() const;
	inline float mag() const;
	inline vec4	 normalized() const;
};

typedef vec2 float2;
typedef vec3 float3;
typedef vec4 float4;

union mat3
{
	vec3	row[3];
	float	elem[9];

	inline float& operator[](const unsigned int i);
	inline const float& operator[](const unsigned int i) const;

	//zero
	static const mat3 zo;
	//identity
	static const mat3 id;
};

union mat4
{
	vec4	row[4];
	float	elem[16];

	inline float& operator[](const unsigned int i);
	inline const float& operator[](const unsigned int i) const;

	//zero
	static const mat4 zo;
	//identity
	static const mat4 id;
};

union Quaternion
{
	//q = a + bi + cj + dk
	struct { float a; float i; float j; float k; };
	vec4   vec;	//show quaternion as a vec4

	//identity
	static const Quaternion id;

	Quaternion() = default;
	Quaternion(const float& a, const float& i, const float& j, const float& k);	//create simple quaternion
	Quaternion(const float& angle, const vec3& v);								//create rotation quaternion, angle in degrees

	inline Quaternion	conjugate() const;
	mat4				mat() const; //get quaternion as mat4
};