
#include "Zombie.hpp"

Zombie*	zombieHorde(int n, std::string name)
{
	/*
		It must allocate N Zombie objects in a single allocation. 
		Then, it has to initialize the zombies, giving each one of them the name passed as parameter.
		The function returns a pointer to the first zombie.
	*/
	if (n <= 0)
	{
		std::cout << "the parameter 'n' is invaild!\n";
		return (NULL);
	}
	//Zombie *zombiehorde = static_cast<Zombie *>(operator new(sizeof(Zombie) * n));
	//for (int i = 0; i < n; ++i)
	//	//zombiehorde[i] = Zombie(name); // default copy constructor.
	//	new (&zombiehorde[i]) Zombie(name);

	Zombie *zombiehorde = new Zombie[n];
	for (int i = 0; i < n; ++i)
		zombiehorde[i].setname(name);

	return (zombiehorde);
}
