#include "FragTrap.hpp"

int main( void )
{
    FragTrap warrior("Mario");
    FragTrap warrior2(warrior);

    warrior.attack("Luigi");
    warrior.takeDamage(10);
    warrior.beRepaired(10);
    warrior.highFivesGuys();
    warrior2.takeDamage(1000);
    warrior.attack("Luigi");
    warrior2.attack("Luigi");
    warrior2.beRepaired(10);
    warrior2.highFivesGuys();
    
    return (0);
}
