#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
}

ScavTrap::~ScavTrap( void )
{
    std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

void    ScavTrap::attack( const std::string& target )
{
    if (_energyPoints <= 0)
    {
        std::cout << "ScavTrap " << _name << " can't attack, is out of energy!" << std::endl;
        return;
    }
    if (_hitPoints <= 0)
    {
        std::cout << "ScavTrap " << _name << " can't attack, he's dead!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints -= 1;
}

void    ScavTrap::guardGate( void)
{
    std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode" << std::endl;
}