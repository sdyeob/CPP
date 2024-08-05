
#include "Zombie.hpp"
#include <stdlib.h>

# define SIZE 10

Zombie*	zombieHorde(int n, std::string name);

//void func(void) { system("leaks zombiehorde"); }

int main(void)
{
	//atexit(func);
	Zombie *zombiehorde = zombieHorde(SIZE, "dongyshi");
	//Zombie *size_error1 = zombieHorde(-5, "dongyshi");
	//Zombie *size_error2 = zombieHorde(0, "dongyshi");
	//if (zombiehorde == NULL)
	//	return (0);
	for (int i = 0; i < SIZE; ++i)
		zombiehorde[i].announce();

	delete [] zombiehorde;
	//delete zombiehorde;
	return (0);
}
