# ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const std::string& name);
        FragTrap(const FragTrap& param);
        FragTrap& operator=(const FragTrap& param); 
        ~FragTrap();

        void highFivesGuys() const ;
};

# endif