
#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): slot_cnt(0)
{
	std::cout << "MateriaSource's default constructor called.\n";
	for (int i = 0; i < 4; ++i)
		slot[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource& param): slot_cnt(param.slot_cnt)
{
	std::cout << "MateriaSource's copy constructor called.\n";
	for (int i = 0; i < slot_cnt; ++i)
	{
		slot[i] = param.slot[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& param)
{
	std::cout << "MateriaSource's assignment operator called.\n";
	for (int i = 0; i < slot_cnt; ++i)
	{
		delete slot[i];
		slot[i] = NULL;
	}

	slot_cnt = param.slot_cnt;
	for (int i = 0; i < slot_cnt; ++i)
	{
		slot[i] = param.slot[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource's destructor called.\n";
	for (int i = 0; i < slot_cnt; ++i)
	{
		delete slot[i];
	}
}

void MateriaSource::learnMateria(AMateria *param)
{
	if (slot_cnt == 4)
	{
		std::cout << "slot is full.\n";
		delete param;
	}
	else
	{
		slot[slot_cnt] = param;
		++slot_cnt;
	}
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (int i = slot_cnt - 1; i >= 0; --i)
	{
		if (slot[i]->getType() == type)
		{
			return (slot[i]->clone());
		}
	}
	std::cout << "Can't find the type.\n";
	return (NULL);
}
