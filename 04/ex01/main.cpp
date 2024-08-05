
#include "Dog.hpp"
#include "Cat.hpp"
#include <stdlib.h>

#define ARRAY_SIZE 4

void	f(){ system("leaks Polymorphism"); }

int main(void)
{
	atexit(f);
	Animal* animal[ARRAY_SIZE];


	for (int i = 0; i < ARRAY_SIZE / 2; ++i)
	{
		animal[i] = new Dog();
		std::cout << std::endl;
	}
	for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; ++i)
	{
		animal[i] = new Cat();
		std::cout << std::endl;
	}


	std::cout << '\n';
	std::cout << "[Print Animal's Type]" << std::endl;
	std::cout << animal[0]->getType() << std::endl;
	std::cout << animal[ARRAY_SIZE - 1]->getType() << std::endl;
	std::cout << '\n';


	std::cout << '\n';
	std::cout << "[Print Animal's Sound]" << std::endl;
	animal[0]->makeSound();
	animal[ARRAY_SIZE - 1]->makeSound();
	std::cout << '\n';


	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		delete animal[i];
		std::cout << std::endl;
	}

	Dog dog;
	dog.addIdea("First idea");
	dog.addIdea("second idea");
	dog.addIdea("Third idea");
	dog.addIdea("Fourth idea");

	std::cout << '\n';
	Dog dog2(dog);
	std::cout << '\n';

	std::cout << '\n';
	for (std::size_t i = 0; i < 4; ++i)
		std::cout << dog2.getIdea(i) << std::endl;
	std::cout << '\n';

	// dog2.getIdea(6);
	// std::cout << "There is no output" << std::endl;
	return (0);
}
