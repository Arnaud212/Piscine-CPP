#include "Dog.hpp"

Dog::Dog( void ) : Animal( "Dog" )
{
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog( const Dog &rhs )
{
    std::cout << "Dog copy constructpr called" << std::endl;
    *this = rhs;
}

Dog& Dog::operator=( const Dog &rhs )
{
    std::cout << "Dog assignment operator called" << std::endl;
    _type = rhs._type;
    return *this;
}

Dog::~Dog( void )
{
    std::cout << "Dog destructor called" << std::endl;
}

void    Dog::makeSound( void ) const
{
    std::cout << "Woof Woof!" << std::endl;
}