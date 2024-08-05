
# ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& param);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& param);
		~ShrubberyCreationForm();

		virtual void concreteExecute() const ;
	private:
		std::string target;
};

# endif
