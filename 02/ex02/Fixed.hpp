
# ifndef FIXED_HPP
# define FIXED_HPP

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

		//comparison
		bool operator>(const Fixed& param);
		bool operator<(const Fixed& param);
		bool operator>=(const Fixed& param);
		bool operator<=(const Fixed& param);
		bool operator==(const Fixed& param);
		bool operator!=(const Fixed& param);

		//arithmetic
		Fixed operator+(const Fixed& param);
		Fixed operator-(const Fixed& param);
		Fixed operator*(const Fixed& param);
		Fixed operator/(const Fixed& param);

		// in/decrement
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		// static member function
		static Fixed& min(Fixed& param1, Fixed& param2);
		static const Fixed& min(const Fixed& param1, const Fixed& param2);
		static Fixed& max(Fixed& param1, Fixed& param2);
		static const Fixed& max(const Fixed& param1, const Fixed& param2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& a);

# endif
