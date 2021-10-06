#include "math/math.hpp"
#include "math/quaternion.hpp"

#include <iostream>

int main()
{
	{
		vec3 a = { 1, 1, 1 };
		vec3 ar = rotateQ(a, (M_PI / 3) * TODEG, { 0, 1, 1 });
		ar.print();
	}
	{
		vec3 a = { 1, 0, 0 };
		vec3 ar = rotateQ(a, 90, { 0, 1, 0 });
		ar.print();
	}
	{
		vec3 a = { 1, 0, 0 };
		Quaternion q1(90, { 0, 1, 0 });
		Quaternion q2(90, { 1, 0, 0 });

		vec3 ar = rotateQ(a, q1 * q2);
		ar.print();
	}
	{
		vec3 a = { 1, 0, 0 };
		Quaternion q1(90, { 0, 1, 0 });
		Quaternion q2(90, { 1, 0, 0 });

		vec3 ar = rotateQ(a, q2 * q1);
		ar.print();
	}
	{
		vec3 a = { 1, 0, 0 };
		Quaternion q1(90, { 0, 1, 0 });
		Quaternion q2(90, { 1, 0, 0 });
		Quaternion q3(90, { 0, 0, 1 });

		vec3 ar = rotateQ(a, q1, q2, q3);
		ar.print();
	}

	return 0;
}