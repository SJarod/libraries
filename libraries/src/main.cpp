#include "math/math.hpp"
#include "math/quaternion.hpp"

#include <iostream>

int main()
{
	Quaternion q(0, { 1, 2, 3 });
	q.v4.print();

	vec3 a = { 1, 2, 3 };
	a.q().v4.print();

	Complex::i i = { 1 };
	Complex::j j = { 1 };
	Complex::k k = { 1 };
	(k * i).print();

	q.conjugate().v4.print();
	return 0;
}