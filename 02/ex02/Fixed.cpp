
#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(): fixed_point(0)
{
	// std::cout << "[Default constructor called]\n";
}

Fixed::Fixed(const int param): fixed_point(param)
{
	// std::cout << "[int param constructor called]\n";
	fixed_point = (fixed_point << Fixed::fraction_point);
}

Fixed::Fixed(const float param)
{
	// std::cout << "[float param constructor called]\n";
	fixed_point = std::roundf(param * (1 << fraction_point));
}

Fixed::Fixed(const Fixed& param): fixed_point(param.fixed_point)
{
	// std::cout << "[Copy constructor called]\n";
}

Fixed& Fixed::operator=(const Fixed& param)
{
	// std::cout << "[Copy assignment operator called]\n";
	fixed_point = param.fixed_point;
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "[Destructor called]\n";
}

int Fixed::getRawBits(void) const
{
	// std::cout << "[getRawBits member function called]\n";
	return (fixed_point);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "[setRawBits member function called]\n";
	fixed_point = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)fixed_point / (float)(1 << fraction_point));
	//const int power = -8;
	//float temp = -(std::pow(2, power + 31) * (bool)(fixed_point & (1 << 31)));

	//for (int i = 30; i >= 0; --i)
	//{
	//	temp = temp + (std::pow(2, power + i) * (bool)(fixed_point & (1 << i)));
	//}
	//return (temp);
}

int Fixed::toInt(void) const
{
	return (fixed_point >> 8);
}

// comparison
bool Fixed::operator>(const Fixed& param)
{
	return (fixed_point > param.fixed_point);
}

bool Fixed::operator<(const Fixed& param)
{
	return (fixed_point < param.fixed_point);
}

bool Fixed::operator>=(const Fixed& param)
{
	return (fixed_point >= param.fixed_point);
}

bool Fixed::operator<=(const Fixed& param)
{
	return (fixed_point <= param.fixed_point);
}

bool Fixed::operator==(const Fixed& param)
{
	return (fixed_point == param.fixed_point);
}

bool Fixed::operator!=(const Fixed& param)
{
	return (fixed_point != param.fixed_point);
}

//arithmetic
Fixed Fixed::operator+(const Fixed& param)
{
	return (toFloat() + param.toFloat());
}

Fixed Fixed::operator-(const Fixed& param)
{
	return (toFloat() - param.toFloat());
}

Fixed Fixed::operator*(const Fixed& param)
{
	return (toFloat() * param.toFloat());
}

Fixed Fixed::operator/(const Fixed& param)
{
	if (param.fixed_point == 0)
	{
		std::cout << "divided zero...!\n";
	}
	return (toFloat() / param.toFloat());
}

// inclement / declement
Fixed& Fixed::operator++()
{
	fixed_point += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;

	fixed_point += 1;
	return (temp);
}

Fixed& Fixed::operator--()
{
	fixed_point -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;

	fixed_point += 1;
	return (temp);
}

// static member function
Fixed& Fixed::min(Fixed& param1, Fixed& param2)
{
	return (param1.fixed_point < param2.fixed_point ? param1 : param2);
}

const Fixed& Fixed::min(const Fixed& param1, const Fixed& param2)
{
	return (param1.fixed_point < param2.fixed_point ? param1 : param2);
}

Fixed& Fixed::max(Fixed& param1, Fixed& param2)
{
	return (param1.fixed_point > param2.fixed_point ? param1 : param2);
}

const Fixed& Fixed::max(const Fixed& param1, const Fixed& param2)
{
	return (param1.fixed_point > param2.fixed_point ? param1 : param2);
}

std::ostream& operator<<(std::ostream& os, const Fixed& param)
{
	os << param.toFloat();
	return (os);
}
