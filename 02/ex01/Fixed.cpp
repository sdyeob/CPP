
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(): fixed_point(0)
{
	std::cout << "[Default constructor called]\n";
}

Fixed::Fixed(const int param): fixed_point(param)
{
	fixed_point = (fixed_point << Fixed::fraction_point);
	std::cout << "[int param constructor called]\n";
}

Fixed::Fixed(const float param)
{
	std::cout << "[float param constructor called]\n";
	fixed_point = std::roundf(param * (1 << fraction_point));
}

Fixed::Fixed(const Fixed& param): fixed_point(param.fixed_point)
{
	std::cout << "[Copy constructor called]\n";
}

Fixed& Fixed::operator=(const Fixed& param)
{
	std::cout << "[Copy assignment operator called]\n";
	fixed_point = param.fixed_point;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "[Destructor called]\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "[getRawBits member function called]\n";
	return (fixed_point);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "[setRawBits member function called]\n";
	fixed_point = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)fixed_point / (float)(1 << fraction_point));
	// const int power = -8;
	// float temp = -(std::pow(2, power + 31) * (bool)(fixed_point & (1 << 31)));

	// for (int i = 30; i >= 0; --i)
	// {
	// 	temp = temp + (std::pow(2, power + i) * (bool)(fixed_point & (1 << i)));
	// }
	// return (temp);
}

int Fixed::toInt(void) const
{
	return (fixed_point >> 8);
}

std::ostream& operator<<(std::ostream& os, const Fixed& param)
{
	os << param.toFloat();
	return (os);
}
