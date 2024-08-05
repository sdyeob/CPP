
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
: name("Invalid Name"), grade_for_sign(1), grade_for_exec(1), is_signed(false)
{
	// std::cout << "Form's default constructor called.\n";
}

Form::Form(const std::string& name, const int& grade_for_sign, const int& grade_for_exec)
: name(name), grade_for_sign(grade_for_sign), grade_for_exec(grade_for_exec), is_signed(false)
{
	// std::cout << "Form's default constructor called with params.\n";
	checkValidGrade();
}

Form::Form(const Form& param)
: name(param.name), grade_for_sign(param.grade_for_sign), grade_for_exec(param.grade_for_exec), is_signed(false)
{
	// std::cout << "Form's copy constructor called with params.\n";
}

Form& Form::operator=(const Form& param)
{
	std::cout << "My Form : " << *this \
		<< ", and param : " << param << " .\n";
	return (*this);
}

Form::~Form()
{
	// std::cout << "Form's destructor called.\n";
}

const std::string& Form::getName() const 
{
	return (name);
}

const int& Form::getGradeForSign() const 
{
	return (grade_for_sign);
}

const int& Form::getGradeForExec() const 
{
	return (grade_for_exec);
}

const bool& Form::getIsSigned() const 
{
	return (is_signed);
}

bool Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= grade_for_sign)
	{
		if (is_signed == false)
		{
			is_signed = true;
			return (true);
		}
		return (false);
	}
	else
		throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "[The Form Information : " \
		<< "name : " << form.getName() \
		<< ", GradeForSign : " << form.getGradeForSign() \
		<< ", GradeForExec : " << form.getGradeForExec() \
		<< ", IsSigned : " << form.getIsSigned() \
		<< " ]\n";
	return (os);
}

const char * Form::GradeTooHighException::what() const throw()
{
	return ("[Form's Exception : Grade is too high]");
};

const char * Form::GradeTooLowException::what() const throw()
{
	return ("[Form's Exception : Grade is too low]");
};

inline void Form::checkValidGrade() const 
{
	if (grade_for_sign < 1 || grade_for_exec < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (grade_for_sign > 150 || grade_for_exec > 150)
	{
		throw Form::GradeTooLowException();
	}
}
