
#include "Dog.hpp"
#include "Cat.hpp"
#include <stdlib.h>

void	f(){ system("leaks Polymorphism"); }

int main(void)
{
	atexit(f);

	std::cout << "[Create Dog Class]" << std::endl;
	Animal* anyanimal = new Dog;

	std::cout << "[make sound for Dog Class]" << std::endl;
	anyanimal->makeSound();

	// Animal animal; // impossible
	// Animal* anyanimal = new Animal;

	delete anyanimal;

	return (0);
}
