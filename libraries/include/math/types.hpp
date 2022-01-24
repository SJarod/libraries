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

union float2
{
	float e[2];

	inline operator vec2() const;
};

union float3
{
	float e[3];

	inline operator vec3() const;
};

union vec2
{
	float  e[2];
	struct { float x; float y; };

	inline operator float2() const;
};

union vec3
{
	float  e[3];
	struct { float x; float y; float z; };
	struct { float i; float j; float k; };
	vec2   xy;

	inline operator float3() const;

	//get vector's quaternion
	Quaternion q() const;

	inline float	sqrMag() const;
	inline float	mag() const;
	inline vec3		normalized() const;
};

union vec4
{
	float  e[4];
	struct { float x; float y; float z; float w; };
	struct { float r; float g; float b; float a; };
	vec3   xyz;
	vec3   rgb;
};

union mat3
{
	vec3	c[3];
	float	e[9];
};

union mat4
{
	vec4	c[4];
	float	e[16];
};

union Quaternion
{
	//q = a + bi + cj + dk
	struct { float a; float i; float j; float k; };
	vec4   v4;	//show quaternion as a vec4

	Quaternion() = default;
	Quaternion(const float& a, const float& i, const float& j, const float& k);	//create simple quaternion
	Quaternion(const float& angle, const vec3& v);								//create rotation quaternion, angle in degrees

	inline Quaternion	conjugate() const;
	mat4				m4() const; //get quaternion as mat4

	inline Quaternion	operator*(const Quaternion& q) const;
};