#include "ScavTrap.hpp"

int main( void )
{
    ScavTrap warrior("Mario");
    ScavTrap warrior2(warrior);

    warrior.attack("Luigi");
    warrior.takeDamage(10);
    warrior.beRepaired(10);
    warrior.guardGate();
    warrior2.takeDamage(1000);
    warrior.attack("Luigi");
    warrior2.attack("Luigi");
    warrior2.beRepaired(10);

    
    return (0);
}
