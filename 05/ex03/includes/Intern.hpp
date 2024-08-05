
# ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	private :
		int checkFormType(const std::string& name) const ;
		std::string job;
	public :
		Intern();
		Intern(const Intern& param);
		Intern& operator=(const Intern& param);
		~Intern();

		AForm* makeForm(const std::string& name, const std::string& target) const ;
};

# endif
