
#include "Character.hpp"

AMateria** Character::floor = new AMateria*[2];
std::size_t Character::floor_size = 2;
std::size_t Character::floor_data_cnt = 0;

Character::Character(): name("No name")
{
	std::cout << "Character's default constructor called.\n";
	for (int i = 0; i < 4; ++i)
		slot[i] = NULL;
}

Character::Character(const std::string& name): name(name)
{
	std::cout << "Character's constructor called with a parameter.\n";
	for (int i = 0; i < 4; ++i)
		slot[i] = NULL;
}

Character::Character(const Character& param): name(param.name)
{
	std::cout << "Character's copy constructor called.\n";
	for (int i = 0; i < 4; ++i)
	{
		if (param.slot[i] != NULL)
			slot[i] = param.slot[i]->clone();
	}
}

Character& Character::operator=(const Character& param)
{
	std::cout << "Character's assignment operator called.\n";
	for (int i = 0; i < 4; ++i)
	{
		if (slot[i] != NULL)
		{
			delete slot[i];
			slot[i] = NULL;
		}
	}
	name = param.name;
	for (int i = 0; i < 4; ++i)
	{
		if (param.slot[i] != NULL)
			slot[i] = param.slot[i]->clone();
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character's destructor called.\n";
	for (int i = 0; i < 4; ++i)
	{
		if (slot[i] != NULL)
			delete slot[i];
	}
}

const std::string& Character::getName() const
{
	return (name);
}

void Character::equip(AMateria* param)
{
	for (int i = 0; i < 4; ++i)
	{
		if (slot[i] == NULL)
		{
			slot[i] = param;
			return ;
		}
	}
	std::cout << "slot is full.\n";
	delete param;
}

void Character::unequip(int idx)
{
	if (idx >= 4 || idx < 0 || slot[idx] == NULL)
	{
		std::cout << "invalid index value.\n";
		return ;
	}
	else
	{
		unequipOnTheFloor(slot[idx]);
		slot[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 4 || idx < 0 || slot[idx] == NULL)
	{
		std::cout << "invalid index value.\n";
		return ;
	}
	else
	{
		slot[idx]->use(target);
	}
}

void Character::unequipOnTheFloor(AMateria* param)
{
	if (floor_size == floor_data_cnt)
	{
		floor_size *= 2;
		AMateria** temp = new AMateria*[floor_size];
		for (std::size_t i = 0; i < floor_data_cnt; ++i)
		{
			temp[i] = floor[i];
		}
		delete [] floor;
		floor = temp;
	}

	floor[floor_data_cnt] = param;
	++floor_data_cnt;
}
