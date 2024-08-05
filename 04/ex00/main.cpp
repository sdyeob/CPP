
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
// #include <stdlib.h>

// void f(void) { system("leaks Polymorphism"); }

int main(void)
{
	// Base *를 가리키는 pointer를 사용해서 Derived 객체를 받을 때 에는, 반드시 Animal 클래스에
	// 존재하는 함수 혹은 변수만 사용될 수 있고, 이에서 벗어나는 조건은 오직 가상 함수만 있다.
	// atexit(f);
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << '\n';
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << '\n';

	std::cout << '\n';
	dog->makeSound();
	cat->makeSound();
	meta->makeSound();
	std::cout << '\n';

	std::cout << '\n';
	const WrongAnimal* wrongmeta = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();
	std::cout << '\n';

	std::cout << '\n';
	wrongcat->makeSound();
	wrongmeta->makeSound();
	std::cout << '\n';

	delete meta;
	delete dog;
	delete cat;

	delete wrongmeta;
	delete wrongcat;
	return (0);
}
