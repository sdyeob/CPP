
# ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& param);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& param);
		~RobotomyRequestForm();

		virtual void concreteExecute() const ;
	private:
		std::string target;
};

# endif
