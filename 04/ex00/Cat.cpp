
#include "Cat.hpp"

Cat::Cat(): Animal()
{
    std::cout << "Cat's default constructor called.\n";
    type = "Cat";
}

Cat::Cat(const Cat& param): Animal()
{
    std::cout << "Cat's copy constructor called.\n";
    type = param.type;
}

Cat& Cat::operator=(const Cat& param)
{
    type = param.type;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat's destructor called.\n";
}

void Cat::makeSound() const
{
    std::cout << "meeeeeeeeeooooooow!\n";
}
