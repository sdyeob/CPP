
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
: name("Invalid Name"), grade_for_sign(1), grade_for_exec(1), is_signed(false)
{
	// std::cout << "AForm's default constructor called.\n";
}

AForm::AForm(const std::string& name, const int& grade_for_sign, const int& grade_for_exec)
: name(name), grade_for_sign(grade_for_sign), grade_for_exec(grade_for_exec), is_signed(false)
{
	// std::cout << "AForm's default constructor called with params.\n";
	checkValidGrade();
}

AForm::AForm(const AForm& param)
: name(param.name), grade_for_sign(param.grade_for_sign), grade_for_exec(param.grade_for_exec), is_signed(false)
{
	// std::cout << "AForm's copy constructor called with params.\n";
}

AForm& AForm::operator=(const AForm& param)
{
	std::cout << *this << std::endl;
	std::cout << param << std::endl;
	return (*this);
}

AForm::~AForm()
{
	// std::cout << "AForm's destructor called.\n";
}

const std::string& AForm::getName() const 
{
	return (name);
}

const int& AForm::getGradeForSign() const 
{
	return (grade_for_sign);
}

const int& AForm::getGradeForExec() const 
{
	return (grade_for_exec);
}

const bool& AForm::getIsSigned() const 
{
	return (is_signed);
}

bool AForm::beSigned(const Bureaucrat& bureaucrat)
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
		throw AForm::GradeTooLowException();
}

bool AForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == true)
	{
		if (executor.getGrade() <= this->getGradeForExec())
		{
			concreteExecute();
			return (true);
		}
		else
		{
			throw AForm::GradeTooLowException();
		}
	}
	else
	{
		return (false);
	}
}

std::ostream& operator<<(std::ostream& os, const AForm& Aform)
{
	os << "[The AForm InAformation : " \
		<< "name : " << Aform.getName() \
		<< ", GradeForSign : " << Aform.getGradeForSign() \
		<< ", GradeForExec : " << Aform.getGradeForExec() \
		<< ", IsSigned : " << Aform.getIsSigned() \
		<< " ]\n";
	return (os);
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return ("[AForm's Exception : Grade is too high]");
};

const char * AForm::GradeTooLowException::what() const throw()
{
	return ("[AForm's Exception : Grade is too low]");
};

inline void AForm::checkValidGrade() const 
{
	if (grade_for_sign < 1 || grade_for_exec < 1)
	{
		throw AForm::GradeTooHighException();
	}
	else if (grade_for_sign > 150 || grade_for_exec > 150)
	{
		throw AForm::GradeTooLowException();
	}
}
