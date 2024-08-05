
#include "Dog.hpp"

Dog::Dog(): Animal()
{
    std::cout << "Dog's default constructor called.\n";
    type = "Dog";
}

Dog::Dog(const Dog& param): Animal()
{
    std::cout << "Dog's copy constructor called.\n";
    type = param.type;
}

Dog& Dog::operator=(const Dog& param)
{
    type = param.type;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog's destructor called.\n";
}

void Dog::makeSound() const
{
    std::cout << "Baaaaaaaaarrrrrrrrk!\n";
}
