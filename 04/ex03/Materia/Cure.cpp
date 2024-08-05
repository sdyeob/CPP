
#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << "Cure's default constructor called.\n";
}

// Cure::Cure(const Cure& param): AMateria("cure")
// {
// 	std::cout << "Cure's copy constructor called.\n";
// }

// Cure& Cure::operator=(const Cure& param)
// {
// 	std::cout << "Cure's assignment operator called.\n";
// 	type = param.type;
// 	return (*this);
// }

Cure::~Cure()
{
	std::cout << "Cure's destructor called.\n";
}

AMateria* Cure::clone() const 
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "Cure: " << "* shoots an Cure bolt at " << target.getName() << " *\n";
}
