# ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private :
        std::string name;
    public :
        DiamondTrap();
        DiamondTrap(const std::string& name);
        DiamondTrap(const DiamondTrap& param);
        DiamondTrap& operator=(const DiamondTrap& param);
        ~DiamondTrap();

        void whoAmI() const ;
};

# endif