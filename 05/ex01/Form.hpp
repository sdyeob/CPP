# ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
class Bureaucrat;

class Form
{
	public :
		Form();
		Form(const std::string& name, const int& grade_for_sign, const int& grade_for_exec);
		Form(const Form& param);
		Form& operator=(const Form& param);
		~Form();

		const std::string& getName() const ;
		const int& getGradeForSign() const ;
		const int& getGradeForExec() const ;
		const bool& getIsSigned() const ;

		bool beSigned(const Bureaucrat& param);

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

std::ostream& operator<<(std::ostream& os, const Form& form);

# endif
