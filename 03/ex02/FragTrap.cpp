
#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
    std::cout << "FragTrap's default constructor called\n";
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
    std::cout << "FragTrap's constructor called with a name parameter\n";
    hp = 100;
    ep = 100;
    damage = 30;
}

FragTrap::FragTrap(const FragTrap& param): ClapTrap(param.name)
{
    std::cout << "FragTrap's copy constructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& param)
{
    name = param.name;
    hp = param.hp;
    ep = param.ep;
    damage = param.damage;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap's destructor called\n";
}

void FragTrap::highFivesGuys() const
{
    std::cout << "FragTrap : highfive Guys!\n";
}