#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " constructor called" << std::endl;
}

FragTrap::~FragTrap( void )
{
    std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

void    FragTrap::attack( const std::string& target )
{
    if (_energyPoints <= 0)
    {
        std::cout << "FragTrap " << _name << " can't attack, is out of energy!" << std::endl;
        return;
    }
    if (_hitPoints <= 0)
    {
        std::cout << "FragTrap " << _name << " can't attack, he's dead!" << std::endl;
        return;
    }
    std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints -= 1;
}

void    FragTrap::highFivesGuys( void )
{
    std::string     line;

    if (_energyPoints <= 0)
    {
        std::cout << "FragTrap " << _name << " can't high five, is out of energy!" << std::endl;
        return;
    }
    if (_hitPoints <= 0)
    {
        std::cout << "FragTrap " << _name << " can't high five, he's dead!" << std::endl;
        return;
    }
    std::cout << "FragTrap " << this->_name << "requests a high five!(press enter to high five)";
	std::getline(std::cin, line);
}
