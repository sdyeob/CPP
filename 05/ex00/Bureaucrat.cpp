
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Invalid Name"), grade(150)
{
	// std::cout << "Bureaucrat's default constructor called.\n";
}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade)
: name(name), grade(grade)
{
	// std::cout << "Bureaucrat's constructor called with a parameter.\n";
	checkValidGrade();
}

Bureaucrat::Bureaucrat(const Bureaucrat& param)
: name(param.name), grade(param.grade)
{
	// std::cout << "Bureaucrat's copy constructor called.\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& param)
{
	grade = param.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Bureaucrat's destructor called.\n";
}

const std::string& Bureaucrat::getName() const 
{
	return (name);
}

const int& Bureaucrat::getGrade() const 
{
	return (grade);
}

void Bureaucrat::incrementGrade()
{
	grade -= 1;
	checkValidGrade();
}

void Bureaucrat::decrementGrade()
{
	grade += 1;
	checkValidGrade();
}

void Bureaucrat::checkValidGrade() const 
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("[Bureaucrat's Exception : Grade is too high]");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("[Bureaucrat's Exception : Grade is too low]");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& param)
{
	os << param.getName() << ", bureaucrat grade " << param.getGrade() << ".\n";
	return (os);
}
