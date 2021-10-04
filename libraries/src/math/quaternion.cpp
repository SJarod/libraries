#include "math/quaternion.hpp"

#include <iostream>

Core::Math::Quaternion::Quaternion(float a, vec3 v)
{
	this->a = a;
	this->i.scalar = v.i;
	this->j.scalar = v.j;
	this->k.scalar = v.k;
}

Quaternion Core::Math::Quaternion::conjugate()
{
	vec3 v = { v4.y, v4.z, v4.w };
	Quaternion qb(a, -v);
	return qb;
}

Quaternion Core::Math::Quaternion::operator*(Quaternion q)
{
	Quaternion qr;	//result
	return qr;
}

vec3 Core::Math::rotateQ(vec3 a, Quaternion q)
{
	return vec3();
}

float Core::Math::Complex::i::operator*(Core::Math::Complex::i i)
{
	return -1 * this->scalar * i.scalar;
}

Core::Math::Complex::k Core::Math::Complex::i::operator*(Core::Math::Complex::j j)
{
	Complex::k k = { this->scalar * j.scalar };
	return k;
}

Core::Math::Complex::j Core::Math::Complex::i::operator*(Core::Math::Complex::k k)
{
	Complex::j j = { -1 * this->scalar * k.scalar };
	return j;
}

void Core::Math::Complex::i::print()
{
	std::cout << scalar << "i" << std::endl;
}

Core::Math::Complex::k Core::Math::Complex::j::operator*(Core::Math::Complex::i i)
{
	Complex::k k = { -1 * this->scalar * i.scalar };
	return k;
}

float Core::Math::Complex::j::operator*(Core::Math::Complex::j j)
{
	return -1 * this->scalar * j.scalar;
}

Core::Math::Complex::i Core::Math::Complex::j::operator*(Core::Math::Complex::k k)
{
	Complex::i i = { this->scalar * k.scalar };
	return i;
}

void Core::Math::Complex::j::print()
{
	std::cout << scalar << "j" << std::endl;
}

Core::Math::Complex::j Core::Math::Complex::k::operator*(Core::Math::Complex::i i)
{
	Complex::j j = { this->scalar * i.scalar };
	return j;
}

Core::Math::Complex::i Core::Math::Complex::k::operator*(Core::Math::Complex::j j)
{
	Complex::i i = { -1 * this->scalar * j.scalar };
	return i;
}

float Core::Math::Complex::k::operator*(Core::Math::Complex::k k)
{
	return -1 * this->scalar * k.scalar;
}

void Core::Math::Complex::k::print()
{
	std::cout << scalar << "k" << std::endl;
}