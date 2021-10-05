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

	return 0;
}