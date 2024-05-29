#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type( "WrongAnimal" )
{
    std::cout << "WrongAnimal contructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : _type(type)
{
    std::cout << "WrongAnimal " << _type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &rhs )
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = rhs;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal &rhs )
{
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    _type = rhs._type;
    return *this;
}

WrongAnimal::~WrongAnimal( void )
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string     WrongAnimal::getType( void ) const
{
    return (_type);
}

void            WrongAnimal::makeSound( void ) const
{
    std::cout << "WrongAnimal makeSound called" << std::endl;
}