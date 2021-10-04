#include "math/quaternion.hpp"

Core::Math::Quaternion::Quaternion(float a, vec3 v)
{
	this->a = a;
	this->i = v.i;
	this->j = v.j;
	this->k = v.k;
}

vec3 Core::Math::rotateQ(vec3 a, Quaternion q)
{
	return vec3();
}