#include "utils/utils.hpp"

#include <thread>

void Utils::SpinLock::lock()
{
	while (flag.test_and_set())
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

void Utils::SpinLock::unlock()
{
	flag.clear();
}

Utils::RawText::RawText(const std::string& str)
	: raw(str)
{
	length = (int)str.length();
}

void Utils::RawText::setCursor(const int pos)
{
	cursor = pos;
}

bool Utils::RawText::getline(std::string& out)
{
	if (cursor >= length)
		return false;

	out = "";
	while (!(raw[cursor] == '\n' || raw[cursor] == '\0'))
		out += raw[cursor++];

	++cursor;
	return true;
}

std::string& Utils::RawText::getRawText()
{
	return raw;
}