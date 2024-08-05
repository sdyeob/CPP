
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(): job("make a form") {}

Intern::Intern(const Intern& param)
{
	job = param.job;
}

Intern& Intern::operator=(const Intern& param)
{
	job = param.job;
	return (*this);
}

Intern::~Intern() {}

int Intern::checkFormType(const std::string& name) const 
{
	const std::string types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; ++i)
	{
		if (types[i] == name)
			return (i);
	}
	return (-1);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) const 
{
	AForm* return_form = NULL;

	switch(checkFormType(name))
	{
		case (0) : 
		{
			std::cout << "Intern creates " << name << ".\n";
			return_form = new ShrubberyCreationForm(target);
			break ;
		}
		case (1) : 
		{
			std::cout << "Intern creates " << name << ".\n";
			return_form = new RobotomyRequestForm(target);
			break ;
		}
		case (2) : 
		{
			std::cout << "Intern creates " << name << ".\n";
			return_form = new PresidentialPardonForm(target);
			break ;
		}
		default :
		{
			std::cout << name << " doesn't exist!\n";
			break ;
		}
	}
	return (return_form);
}

