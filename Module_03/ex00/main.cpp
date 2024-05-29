#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap warrior("Mario");
    ClapTrap warrior2(warrior);

    warrior.attack("Luigi");
    warrior.takeDamage(5);
    warrior.beRepaired(2);
    warrior.takeDamage(100);
    warrior.attack("Luigi");
    warrior.beRepaired(5);
    warrior2.attack("Luigi");
    
    return (0);
}
