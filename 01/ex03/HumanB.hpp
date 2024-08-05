
# ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private :
		const std::string &name;
		Weapon *weapon;
	public :
		HumanB(const std::string &name);
		void attack(void) const ;
		void setWeapon(Weapon &newweapon);
};

# endif
