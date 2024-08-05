
# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
class Form;

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
		void signForm(Form& param) const ;

		class GradeTooHighException : public std::exception
		{ const char* what() const throw(); };
		class GradeTooLowException : public std::exception
		{ const char* what() const throw(); };

	private :
		const std::string name;
		int grade; // 1 is highest and 150 is lowest
		inline void checkValidGrade() const ;
};

//const char* what() constcp throw();
//static Bureaucrat GradeTooHighException();
//static Bureaucrat GradeTooLowException();
std::ostream& operator<<(std::ostream& os, const Bureaucrat& param);

# endif
