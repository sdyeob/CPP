
#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap tom("Tom");
    ClapTrap albert("Albert");

    tom.attack(albert.getName());
    albert.takeDamage(tom.getDamage());
    albert.beRepaired(1);
    
    for (int i = 0; i < 10; i++)
        albert.beRepaired(1);

    albert.attack(tom.getName());

    return (0);
}