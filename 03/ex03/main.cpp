
#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap a("Tom");

    std::cout << '\n';
    a.attack("Tom");
    std::cout << '\n';

    std::cout << '\n';
    a.whoAmI();
    std::cout << '\n';

    std::cout << '\n';
    a.guardGate();
    std::cout << '\n';

    std::cout << '\n';
    a.highFivesGuys();
    std::cout << '\n';

    return (0);
}