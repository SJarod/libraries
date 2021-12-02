#include "math/math.hpp"
#include "math/quaternion.hpp"
#include "utils/singleton.hpp"

#include <iostream>

#include "utils/memleaks.hpp"

class Test : public Singleton<Test>
{
	friend class Singleton<Test>;

private:
	Test() {}

	int a = 1;
	int b = 2;

public:
	void testing();
	void plus();
};

int main()
{
	initMemleaksDebug();

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
	{
		vec4 a = { 1, 0, 0 , 1};
		Quaternion q1(90, { 0, 1, 0 });
		Quaternion q2(90, { 1, 0, 0 });
		Quaternion q3(90, { 0, 0, 1 });

		mat4 m = rotateYMatrix(90) * rotateXMatrix(90) * rotateZMatrix(90);
		m.print();
		(m * a).print();
		mat4 mq = (q3 * q2 * q1).m4();
		mq.print();
		(mq * a).print();
	}
	{
		Test* t = Test::getInstance();
		t->testing();
		t->plus();
		Test* t2 = Test::getInstance();
		t2->testing();

		Test::end();
	}

	return 0;
}

void Test::testing()
{
	std::cout << getInstance() << std::endl;
	std::cout << "a " << a << " b " << b << std::endl;
}

void Test::plus()
{
	a += b;
}