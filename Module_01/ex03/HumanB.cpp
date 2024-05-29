#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
    this->_weapon = NULL;
    return;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}

void    HumanB::attack(void)
{
    if (_weapon)
        std::cout << this->_name << " attacks with their " << (*_weapon).getType() << std::endl;
    else
        std::cout << _name << " has no weapon to attack" << std::endl;
}

HumanB::~HumanB(void)
{
    return;
}