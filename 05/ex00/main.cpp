
#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat a;
		a.decrementGrade();
	} catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat a("dongyshi", 1);
		a.incrementGrade();
	} catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat a("dongyshi", -1);
	} catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat a("dongyshi", 20);
	a.incrementGrade();
	a.incrementGrade();
	a.decrementGrade();

	std::cout << a << std::endl;

	return (0);
}
