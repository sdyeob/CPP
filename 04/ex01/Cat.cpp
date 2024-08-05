
#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat's default constructor called.\n";
	type = "Cat";
	cat_brain = new Brain();
}

Cat::Cat(const Cat& param): Animal()
{
	std::cout << "Cat's copy constructor called.\n";
	cat_brain = new Brain();
	*this = param;
}

Cat& Cat::operator=(const Cat& param)
{
	std::cout << "Cat's assignment operator called.\n";
	type = param.type;
	*cat_brain = *(param.cat_brain);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat's destructor called.\n";
	delete cat_brain;
}

void Cat::makeSound() const
{
	std::cout << "meeeeeeeeeeeeeeooooooooooooow!\n";
}

void Cat::addIdea(const std::string& idea)
{
	cat_brain->addIdea(idea);
}

const std::string& Cat::getIdea(const std::size_t& idx) const 
{
	return (cat_brain->getIdea(idx));
}
