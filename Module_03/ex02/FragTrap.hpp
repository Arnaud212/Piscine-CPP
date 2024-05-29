#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
    public:

    FragTrap( std::string name );
    ~FragTrap( void );

    void attack( const std::string& target );
    void highFivesGuys( void );

};

#endif