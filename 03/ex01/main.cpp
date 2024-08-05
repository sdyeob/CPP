
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap tom("Tom");
    ScavTrap albert("Albert");

    std::cout << "\n";
    tom.attack(albert.getName());
    albert.takeDamage(tom.getDamage());
    std::cout << "\n";

    std::cout << "\n";
    albert.beRepaired(1);
    std::cout << "\n";

    std::cout << "\n";
    albert.attack(tom.getName());
    tom.takeDamage(albert.getDamage());
    std::cout << "\n";

    std::cout << "\n";
    tom.beRepaired(1);
    std::cout << "\n";
    
    std::cout << "\n";
    albert.ClapTrap::attack(tom.getName());
    std::cout << "\n";

    std::cout << "\n";
    for (int i = 0; i < 50; i++)
        albert.beRepaired(1);
    std::cout << "\n";
    
    std::cout << "\n";
    albert.attack(tom.getName());
    albert.guardGate();
    std::cout << "\n";

    return (0);
}