
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <stdlib.h>

void f(void) { system("leaks files"); }

int main(void)
{
	atexit(f);
	AForm* new_form = new ShrubberyCreationForm("hello");
	AForm* new_form1 = new RobotomyRequestForm("hello");
	AForm* new_form2 = new PresidentialPardonForm("hello");
	Bureaucrat a("dongyshi", 1);

	std::cout << std::endl;
	a.signForm(*new_form);
	a.executeForm(*new_form);
	std::cout << std::endl;

	std::cout << std::endl;
	a.signForm(*new_form1);
	a.executeForm(*new_form1);
	std::cout << std::endl;

	std::cout << std::endl;
	a.signForm(*new_form2);
	a.executeForm(*new_form2);
	std::cout << std::endl;

	delete new_form;
	delete new_form1;
	delete new_form2;

	return (0);
}
