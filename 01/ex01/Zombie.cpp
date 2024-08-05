
#include "Zombie.hpp"

Zombie::Zombie(void) {}

Zombie::Zombie(std::string name): name(name) {}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setname(const std::string& name)
{
	this->name = name;
}

Zombie::~Zombie(void)
{
	std::cout << name << "is destructed\n";
}
