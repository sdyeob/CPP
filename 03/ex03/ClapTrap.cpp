
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("noname"), hp(10), ep(10), damage(0)
{
    std::cout << "ClapTrap's default constructor called\n";
}

ClapTrap::ClapTrap(const std::string& name): name(name), hp(10), ep(10), damage(0)
{
    std::cout << "ClapTrap's constructor called with a name parameter\n";
}

ClapTrap::ClapTrap(const ClapTrap& param): name(param.name), hp(param.hp), ep(param.ep), damage(param.damage)
{
    std::cout << "ClapTrap's copy constructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& param)
{
    name = param.name;
    hp = param.hp;
    ep = param.ep;
    damage = param.damage;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap's destructor called\n";
}

void ClapTrap::attack(const std::string& target)
{
    if (hp <= 0)
    {
        std::cout << "already died\n";
    }
    else if (ep == 0)
    {
        std::cout << "ep is not enough\n";
    }
    else
    {
        std::cout << "ClapTrap " << name << " attacks " \
            << target << ", causing " << damage << " points of damage!\n";
        --ep;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hp <= 0)
    {
        std::cout << "already died" << std::endl;
    }
    else
    {
        hp -= amount;
        std::cout << "ClapTrap " << name << " is attacked with damage " << amount << "!\n";
        if (hp <= 0)
            std::cout << "ClapTrap " << name << "is died!\n";
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hp <= 0)
    {
        std::cout << "already died\n";
    }
    else if (ep == 0)
    {
        std::cout << "ep is not enough\n";
    }
    else
    {
        std::cout << "ClapTrap " << name << " repair itself!\n";
        --ep;
        hp += amount;
    }
}

const std::string& ClapTrap::getName() const
{
    return (name);
}

const int& ClapTrap::getDamage() const
{
    return (damage);
}