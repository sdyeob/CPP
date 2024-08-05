
# ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private :
		int fixed_point;
		static const int fraction_point = 8;
	public :
		Fixed();
		Fixed(const Fixed& param);
		Fixed& operator=(const Fixed& param);
		~Fixed();

		int getRawBits(void) const ;
		void setRawBits(int const raw);
};

# endif
