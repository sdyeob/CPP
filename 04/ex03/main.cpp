
#include <stdlib.h>
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void f() { system("leaks Polymorphism"); }

int main() {
	atexit(f);

	/*
		Basic Test
	*/
	std::cout << '\n';
	std::cout << "[Create MateriaSource]" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << '\n';

	std::cout << '\n';
	std::cout << "[Create Character Me]" << std::endl;
	ICharacter* me = new Character("me");
	std::cout << '\n';

	std::cout << '\n';
	std::cout << "[Create AMateria * 2]" << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << "tmp : " << tmp->getType() << " is equipped" << std::endl;
	std::cout << '\n';

	std::cout << '\n';
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << "tmp : " << tmp->getType() << " is equipped" << std::endl;
	std::cout << '\n';

	std::cout << '\n';
	std::cout << "[Create Character bob and Me attack bob]" << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << '\n';

	std::cout << '\n';
	std::cout << "[Unequip]" << std::endl;
	me->unequip(3);
	me->unequip(1);
	me->unequip(0);
	std::cout << '\n';


	for (std::size_t i = 0; i < Character::floor_data_cnt; ++i)
	{
		delete Character::floor[i];
	}
	delete [] Character::floor;


	std::cout << '\n';
	delete bob;
	std::cout << '\n';

	std::cout << '\n';
	delete me;
	std::cout << '\n';

	std::cout << '\n';
	delete src;
	std::cout << '\n';


	/*
		Character's equip and unequip
	*/
	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

	// std::cout << '\n';
	// Character c1;
	// c1.equip(src->createMateria("ice"));
	// c1.equip(src->createMateria("ice"));
	// c1.equip(src->createMateria("ice"));
	// c1.equip(src->createMateria("ice"));
	// c1.equip(src->createMateria("ice"));
	// c1.unequip(5);
	// c1.unequip(-1);
	// c1.unequip(3);
	// c1.unequip(3);

	// c1.unequip(0);
	// c1.unequip(1);
	// c1.unequip(2);
	// c1.equip(src->createMateria("ice"));
	// std::cout << '\n';

	// delete src;
	return 0;
}
