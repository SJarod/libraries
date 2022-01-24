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
		vec3 ar = Math3::rotateQ(a, (M_PI / 3) * TODEG, { 0, 1, 1 });
		std::cout << ar << std::endl;
	}
	{
		vec3 a = { 1, 0, 0 };
		vec3 ar = Math3::rotateQ(a, 90, { 0, 1, 0 });
		std::cout << ar << std::endl;
	}
	{
		vec3 a = { 1, 0, 0 };
		Quaternion q1(90, { 0, 1, 0 });
		Quaternion q2(90, { 1, 0, 0 });

		vec3 ar = Math3::rotateQ(a, q1 * q2);
		std::cout << ar << std::endl;
	}
	{
		vec3 a = { 1, 0, 0 };
		Quaternion q1(90, { 0, 1, 0 });
		Quaternion q2(90, { 1, 0, 0 });

		vec3 ar = Math3::rotateQ(a, q2 * q1);
		std::cout << ar << std::endl;
	}
	{
		vec3 a = { 1, 0, 0 };
		Quaternion q1(90, { 0, 1, 0 });
		Quaternion q2(90, { 1, 0, 0 });
		Quaternion q3(90, { 0, 0, 1 });

		vec3 ar = Math3::rotateQ(a, q1, q2, q3);
		std::cout << ar << std::endl;
	}
	{
		vec4 a = { 1, 0, 0 , 1};
		Quaternion q1(90, { 0, 1, 0 });
		Quaternion q2(90, { 1, 0, 0 });
		Quaternion q3(90, { 0, 0, 1 });

		mat4 m = Math3::rotateYMatrix(90) * Math3::rotateXMatrix(90) * Math3::rotateZMatrix(90);
		std::cout << m << std::endl;
		std::cout << (m * a) << std::endl;
		mat4 mq = (q3 * q2 * q1).m4();
		std::cout << mq << std::endl;
		std::cout << (mq * a) << std::endl;
	}
	{
		Test* t = Test::getInstance();
		t->testing();
		t->plus();
		Test* t2 = Test::getInstance();
		t2->testing();

		Test::destroy();
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