
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("No type")
{
    std::cout << "WrongAnimal's default constructor called.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& param): type(param.type)
{
    std::cout << "WrongAnimal's copy constructor called.\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& param)
{
    type = param.type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal's destructor called.\n";
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal can't make sound.\n";
}

const std::string& WrongAnimal::getType() const
{
	return (type);
}
