
#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
    std::cout << "WrongCat's default constructor called.\n";
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& param): WrongAnimal()
{
    std::cout << "WrongCat's copy constructor called.\n";
    type = param.type;
}

WrongCat& WrongCat::operator=(const WrongCat& param)
{
    type = param.type;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat's destructor called.\n";
}

void WrongCat::makeSound() const
{
    std::cout << "meeeeeeeeeeeeeeoooooooooooow!\n";
}
