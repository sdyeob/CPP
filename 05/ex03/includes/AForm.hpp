# ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
class Bureaucrat;

class AForm
{
	public :
		AForm();
		AForm(const std::string& name, const int& grade_for_sign, const int& grade_for_exec);
		AForm(const AForm& param);
		AForm& operator=(const AForm& param);
		virtual ~AForm();

		const std::string& getName() const ;
		const int& getGradeForSign() const ;
		const int& getGradeForExec() const ;
		const bool& getIsSigned() const ;

		bool beSigned(const Bureaucrat& param);
		bool execute(Bureaucrat const & executor) const ;
		virtual void concreteExecute() const = 0;

		class GradeTooHighException : public std::exception
		{ const char * what() const throw(); };
		class GradeTooLowException : public std::exception
		{ const char * what() const throw(); };

	private :
		const std::string name;
		const int grade_for_sign;
		const int grade_for_exec;
		bool is_signed;
		inline void checkValidGrade() const ;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

# endif
