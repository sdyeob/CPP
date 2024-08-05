
# ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private :
		int fixed_point;
		static const int fraction_point = 8;
	public :
		Fixed();
		Fixed(const int param); // convert param to the corresponding fixed point value.
		Fixed(const float param); //  convert param to the corresponding fixed point value.
		Fixed(const Fixed& param);
		Fixed& operator=(const Fixed& param);
		~Fixed();

		int getRawBits(void) const; // return the raw value of the fixed point value.
		void setRawBits(int const raw); // set the raw value of the fixed point number.
		float toFloat(void) const; // convert the fixed-point value to a floating point value;
		int toInt(void) const; // convert the fixed point value to an integer value.
};

std::ostream& operator<<(std::ostream& os, const Fixed& a);

# endif
