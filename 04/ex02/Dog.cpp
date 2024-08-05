
#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog's default constructor called.\n";
	type = "Dog";
	dog_brain = new Brain();
}

Dog::Dog(const Dog& param): Animal()
{
	std::cout << "Dog's copy constructor called.\n";
	dog_brain = new Brain();
	*this = param;
}

Dog& Dog::operator=(const Dog& param)
{
	std::cout << "Dog's assignment operator called.\n";
	type = param.type;
	*dog_brain = *(param.dog_brain);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog's destructor called.\n";
	delete dog_brain;
}

void Dog::makeSound() const
{
	std::cout << "Baaaaaaaaaaaaaarrrrrrrrrrrrrk!\n";
}

void Dog::addIdea(const std::string& idea)
{
	dog_brain->addIdea(idea);
}

const std::string& Dog::getIdea(const std::size_t& idx) const 
{
	return (dog_brain->getIdea(idx));
}
