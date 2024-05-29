#include "AAnimal.hpp"


AAnimal::AAnimal( void ) : _type( "AAnimal" )
{
    std::cout << "AAnimal contructor called" << std::endl;
}

AAnimal::AAnimal( std::string type ) : _type(type)
{
    std::cout << "AAnimal " << _type << " constructor called" << std::endl;
}

AAnimal::AAnimal( const AAnimal &rhs )
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = rhs;
}

AAnimal& AAnimal::operator=( const AAnimal &rhs )
{
    std::cout << "AAnimal assignment operator called" << std::endl;
    _type = rhs._type;
    return *this;
}

AAnimal::~AAnimal( void )
{
    std::cout << "AAnimal destructor called" << std::endl;
}

std::string     AAnimal::getType( void ) const
{
    return (_type);
}

void            AAnimal::makeSound( void ) const
{
    std::cout << "AAnimal makeSound called" << std::endl;
}