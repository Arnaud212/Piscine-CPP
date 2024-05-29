#include "Animal.hpp"

Animal::Animal( void ) : _type( "Animal" )
{
    std::cout << "Animal contructor called" << std::endl;
}

Animal::Animal( std::string type ) : _type(type)
{
    std::cout << "Animal " << _type << " constructor called" << std::endl;
}

Animal::Animal( const Animal &rhs )
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = rhs;
}

Animal& Animal::operator=( const Animal &rhs )
{
    std::cout << "Animal assignment operator called" << std::endl;
    _type = rhs._type;
    return *this;
}

Animal::~Animal( void )
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string     Animal::getType( void ) const
{
    return (_type);
}

void            Animal::makeSound( void ) const
{
    std::cout << "Animal makeSound called" << std::endl;
}

