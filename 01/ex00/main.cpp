
#include "Zombie.hpp"
#include <stdlib.h>

Zombie* newZombie(std::string name);
void randomChump(std::string name);

//void func(void) { system("leaks firstzombie"); }

int main(void)
{
	//atexit(func);
	Zombie *dongyshi = newZombie("Dongyshi");
	dongyshi->announce();
	delete dongyshi;

	randomChump("the new Zombie");
	return (0);
}
