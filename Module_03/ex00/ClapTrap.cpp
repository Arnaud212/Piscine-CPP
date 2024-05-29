#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "String constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &rhs )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

ClapTrap::~ClapTrap( void )
{
    std::cout << "Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=( const ClapTrap &rhs )
{
    _name = rhs._name;
    _hitPoints = rhs._hitPoints;
    _energyPoints = rhs._energyPoints;
    _attackDamage = rhs._attackDamage;
    return *this;
}

void    ClapTrap::attack( const std::string& target )
{
    if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't attack, is out of energy!" << std::endl;
        return;
    } 
    if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't attack, he's dead!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints -= 1;
}

void    ClapTrap::takeDamage( unsigned int amount )
{
    if ((int)amount >= _hitPoints)
    {
        std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
        _hitPoints -= amount;
        return;
    }
    std::cout << "ClapTrap " << _name << " takes " << amount << " damage!" << std::endl;
    _hitPoints -= amount;
}

void    ClapTrap::beRepaired( unsigned int amount ) 
{
    if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
        return;
    }
    if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't repair himself, he's dead!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points!" << std::endl;
    _hitPoints += amount;
    _energyPoints -= 1;
}


