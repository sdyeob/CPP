
#include "Animal.hpp"

Animal::Animal(): type("No type")
{
    std::cout << "Animal's default constructor called.\n";
}

Animal::Animal(const Animal& param): type(param.type)
{
    std::cout << "Animal's copy constructor called.\n";
}

Animal& Animal::operator=(const Animal& param)
{
    type = param.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal's destructor called.\n";
}

const std::string& Animal::getType() const
{
	return (type);
}
