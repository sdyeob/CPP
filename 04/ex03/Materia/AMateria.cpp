
#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(): type("No Type")
{
	std::cout << "AMateria's default constructor called.\n";
}

AMateria::AMateria(const std::string& type): type(type)
{
	std::cout << "AMateria's constructor called with a type parameter.\n";
}

AMateria::~AMateria()
{
	std::cout << "AMateria's destructor called.\n";
}

const std::string& AMateria::getType() const 
{
	return (type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << type << ": * shoots an ice bolt at " << target.getName() << " *\n";
}

// AMateria::AMateria(const AMateria& param): type(param.type)
// {
// 	std::cout << "AMateria's copy constructor called.\n";
// }

// AMateria& AMateria::operator=(const AMateria& param)
// {
// 	std::cout << "AMateria's assignment operator called.\n";
// 	return (*this);
// }
