# ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(const PresidentialPardonForm& param);
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& param);
		~PresidentialPardonForm();

		virtual void concreteExecute() const ;
	private:
		std::string target;

		PresidentialPardonForm();
};

# endif
