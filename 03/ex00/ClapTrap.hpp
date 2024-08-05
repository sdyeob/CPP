# ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private :
        std::string name;
        int hp;
        int ep;
        int damage;
    public :
        ClapTrap();
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& param);
        ClapTrap& operator=(const ClapTrap& param);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        const std::string& getName() const;
        const int& getDamage() const;
};

# endif