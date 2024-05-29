#include "Weapon.hpp"

Weapon::Weapon(std::string weapon)
{
    this->_type = weapon;
    return;
}

Weapon::Weapon(void)
{
    return;
}

Weapon::~Weapon()
{
    return;
}

const std::string& Weapon::getType(void)
{
    return (this->_type);
}

void    Weapon::setType(std::string Type)
{
    this->_type = Type;
}