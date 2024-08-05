# ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public :
        ScavTrap();
        ScavTrap(const std::string& name);
        ScavTrap(const ScavTrap& param);
        ScavTrap& operator=(const ScavTrap& param); 
        ~ScavTrap();

        void attack(const std::string& target);
        void guardGate() const;
};

# endif