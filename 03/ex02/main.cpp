
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap base("Base");
    FragTrap tom("Tom");
    ScavTrap albert("Albert");

    std::cout << '\n';
    tom.attack(albert.getName());
    albert.takeDamage(tom.getDamage());
    std::cout << '\n';

    std::cout << '\n';
    albert.attack(tom.getName());
    tom.takeDamage(albert.getDamage());
    std::cout << '\n';

    std::cout << '\n';
    tom.highFivesGuys();
    std::cout << '\n';

    return (0);
}