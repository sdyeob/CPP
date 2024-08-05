
#include "HumanB.hpp"

HumanB::HumanB(const std::string &name)
:name(name), weapon(NULL) {}

void	HumanB::attack(void) const
{
	if (weapon != NULL)
		std::cout << name << " attacks with their " << weapon->getType() << '\n';
}

void	HumanB::setWeapon(Weapon &newweapon)
{
	weapon = &newweapon;
}
