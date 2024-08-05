
#include <stdlib.h>
#include "HumanA.hpp"
#include "HumanB.hpp"

//void	func(void) { system("leaks weapon"); }

int main(void) {
	//atexit(func);
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon  club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
