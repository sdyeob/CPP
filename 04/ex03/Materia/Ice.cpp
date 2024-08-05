
#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout << "Ice's default constructor called.\n";
}

// Ice::Ice(const Ice& param): AMateria("ice")
// {
// 	std::cout << "Ice's copy constructor called.\n";
// }

// Ice& Ice::operator=(const Ice& param)
// {
// 	std::cout << "Ice's assignment operator called.\n";
// 	type = param.type;
// 	return (*this);
// }

Ice::~Ice()
{
	std::cout << "Ice's destructor called.\n";
}

AMateria* Ice::clone() const 
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "Ice: " << "* shoots an ice bolt at " << target.getName() << " *\n";
}
