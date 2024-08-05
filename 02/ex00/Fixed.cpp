
#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(): fixed_point(0)
{
	std::cout << "[Default constructor called]\n";
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
