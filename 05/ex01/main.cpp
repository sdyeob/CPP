
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	Bureaucrat b1("b1", 30);
	Bureaucrat b2("b2", 40);
	Form form("a form", 30, 30);

	std::cout << std::endl;
	b1.signForm(form);
	std::cout << std::endl;
	b1.signForm(form);

	std::cout << std::endl;
	b2.signForm(form);
	std::cout << std::endl;
	return (0);
}
