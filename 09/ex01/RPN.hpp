
# ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <exception>

class RPN
{
	private :
		std::stack<double> st;
		std::string whole_string;

	private :
		bool is_operator(char c);
		bool is_n_number_under_ten(char c);
		double get_calculated_value(char op, double val1, double val2);
	public :
		//RPN();
		RPN(char *str);
		//RPN(const RPN& origin);
		//RPN& operator=(const RPN& origin);
		//~RPN();

	public :
		void	calculate();
};

# endif
