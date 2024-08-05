
# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
class AForm;

class Bureaucrat
{
	public :
		Bureaucrat();
		Bureaucrat(const std::string& name, const int& grade);
		Bureaucrat(const Bureaucrat& param);
		Bureaucrat& operator=(const Bureaucrat& param);
		~Bureaucrat();

		const std::string& getName() const ;
		const int& getGrade() const ;
		void incrementGrade(); // increment is grade -= 1;
		void decrementGrade(); // decrement is grade += 1;
		void signForm(AForm& param) const ;

		void executeForm(AForm const & form) const ;

		class GradeTooHighException : public std::exception
		{ const char* what() const throw(); };
		class GradeTooLowException : public std::exception
		{ const char* what() const throw(); };

	private :
		const std::string name;
		int grade; // 1 is highest and 150 is lowest
		void checkValidGrade() const ;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& param);

# endif
