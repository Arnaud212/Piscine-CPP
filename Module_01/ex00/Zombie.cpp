#include "Zombie.hpp"

Zombie::Zombie(std::string ZombieName)
{
    name = ZombieName;
    return;
}

Zombie::~Zombie(void)
{
    std::cout << this->name << " has been destroyed" << std::endl;
    return;
}

void    Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
