
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 72, 45)
{
	//std::cout << "PresidentialPardonForm's default constructor called.\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
 : AForm("PresidentialPardonForm", 72, 45), target(target)
{
	//std::cout << "PresidentialPardonForm's constructor called with a target parameter.\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& param)
: AForm("PresidentialPardonForm", 72, 45), target(param.target)
{
	//std::cout << "PresidentialPardonForm's copy constructor called.\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& param)
{
	//std::cout << "PresidentialPardonForm's assignment operator called.\n";
	target = param.target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	//std::cout << "PresidentialPardonForm's destructor called.\n";
}

void PresidentialPardonForm::concreteExecute() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n";
}
