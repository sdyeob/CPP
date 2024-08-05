
#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	{
		//std::cout << "[Basic Operators with Positive values]" << std::endl;
		Fixed a = 20;
		Fixed b = 3;

		std::cout << "a + b :" << a + b << std::endl;
		std::cout << "a - b :" << a - b << std::endl;
		std::cout << "a * b :" << a * b << std::endl;
		std::cout << "a / b :" << a / b << std::endl;
	}
	{
		//std::cout << "[Basic Operators with Positive values]" << std::endl;
		Fixed a = -20;
		Fixed b = -3;

		std::cout << "a + b :" << a + b << std::endl;
		std::cout << "a - b :" << a - b << std::endl;
		std::cout << "a * b :" << a * b << std::endl;
		std::cout << "a / b :" << a / b << std::endl;
	}
	{
		//std::cout << "[Basic Operators with Positive values]" << std::endl;
		Fixed a = 10.5f;
		Fixed b = 1.25f;
		Fixed zero;

		std::cout << "a + b :" << a + b << std::endl;
		std::cout << "a - b :" << a - b << std::endl;
		std::cout << "a * b :" << a * b << std::endl;
		std::cout << "a / b :" << a / b << std::endl;
		std::cout << "a / 0 :" << a / zero << std::endl;
	}
	{
		//std::cout << "[Basic Operators with Positive values]" << std::endl;
		Fixed a = 20;
		Fixed b = -3;
		Fixed c = 20;

		std::cout << "a > b :" << (a > b) << std::endl;
		std::cout << "a < b :" << (a < b) << std::endl;
		std::cout << "a >= b :" << (a >= b) << std::endl;
		std::cout << "a <= b :" << (a <= b) << std::endl;
		std::cout << "a == b :" << (a == b) << std::endl;
		std::cout << "a == c :" << (a == c) << std::endl;
		std::cout << "a != b :" << (a != b) << std::endl;
		std::cout << "a != c :" << (a != c) << std::endl;
	}
	{
		//std::cout << "[Basic Operators with Positive values]" << std::endl;
		Fixed a;

		std::cout << "a : " << a << std::endl;
		std::cout << "a : " << ++a << std::endl;
		std::cout << "a : " << a++ << std::endl;
		std::cout << "a : " << a << std::endl;
	}
	{
		Fixed a = 12.125f;
		Fixed b = 25;

		std::cout << Fixed::min(a, b) << std::endl;
		std::cout << Fixed::min(12.125f, 25) << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
		std::cout << Fixed::max(12.125f, 25) << std::endl;
	}
	return 0;
}
