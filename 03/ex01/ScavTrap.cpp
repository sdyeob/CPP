#include "ScavTrap.hpp"

// initialization list can't be used because hp, ep, damage are ClapTrap's attributes.
ScavTrap::ScavTrap(): ClapTrap()
{
    std::cout << "ScavTrap's default constructor called\n";
    hp = 100;
    ep = 50;
    damage = 20;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name)
{
    std::cout << "ScavTrap's constructor called with a name parameter\n";
    hp = 100;
    ep = 50;
    damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& param): ClapTrap(param)
{
    std::cout << "ScavTrap's copy constructor called\n";
    hp = 100;
    ep = 50;
    damage = 20;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& param)
{
    name = param.name;
    hp = param.hp;
    ep = param.ep;
    damage = param.damage;
    return (*this);
}

ScavTrap::~ScavTrap()
{
   std::cout << "ScavTrap's destructor called\n";
}

void ScavTrap::attack(const std::string& target) // overriding
{
    if (hp <= 0)
    {
        std::cout << "ScavTrap is already died\n";
    }
    else if (ep == 0)
    {
        std::cout << "ScavTrap's ep is not enough\n";
    }
    else
    {
        std::cout << "ScavTrap " << name << " attacks " \
            << target << ", causing " << damage << " points of damage!\n";
        --ep;
    }
}

void ScavTrap::guardGate() const
{
    std::cout << name << " is on the guardgate mode!\n";
}
