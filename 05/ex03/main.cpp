
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <stdlib.h>

void f(void) { system("leaks Interns"); }
int main(void)
{
	atexit(f);
	// "shrubbery creation", "robotomy request", "presidential pardon";
	Bureaucrat employer("dongyshi", 5);

	Intern someRandomIntern;
	AForm* ptr_form;

	std::cout << std::endl;
	ptr_form = someRandomIntern.makeForm("robotomy request", "home");
	std::cout << std::endl;

	std::cout << std::endl;
	employer.signForm(*ptr_form);
	std::cout << std::endl;

	std::cout << std::endl;
	employer.executeForm(*ptr_form);
	std::cout << std::endl;

	if (ptr_form)
	{
		delete ptr_form;
	}

	ptr_form = someRandomIntern.makeForm("shrubbery creatio", "home");
	return (0);
}
