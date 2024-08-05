
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap()
{
    std::cout << "DiamondTrap's default constructor called\n";
    ClapTrap::name.append("_clap_name");
    name = "noname";
    hp = 100;
    ep = 50;
    damage = 30;
}

DiamondTrap::DiamondTrap(const std::string& name) \
    : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), name(name)
{
    std::cout << "DiamondTrap's constructor called with a name parameter.\n";
    hp = 100;
    ep = 50;
    damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& param) \
    : ClapTrap(param.name + "_clap_name"), ScavTrap(), FragTrap(), name(param.name)
{
    std::cout << "DiamondTrap's copy constructor called\n";
    hp = 100;
    ep = 50;
    damage = 30;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& param)
{
    ClapTrap::name = param.ClapTrap::name;
    name = param.name;
    hp = param.hp;
    ep = param.ep;
    damage = param.damage;
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap's destructor called\n";
}

// This member function will display both its name and its ClapTrap name.
void DiamondTrap::whoAmI() const
{
    std::cout << "DiamondTrap's name : " << name \
        << ", ClapTrap's name : " << ClapTrap::name << std::endl;
}
