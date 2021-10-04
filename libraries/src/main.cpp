#include "math/math.hpp"
#include "math/quaternion.hpp"

int main()
{
	Quaternion q(0, { 1, 2, 3 });
	q.v4.print();

	vec3 a = { 1, 2, 3 };
	a.q().v4.print();
	return 0;
}