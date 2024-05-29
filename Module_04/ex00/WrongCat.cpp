#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat &rhs )
{
    std::cout << "WrongCat copy constructpr called" << std::endl;
    *this = rhs;
}

WrongCat& WrongCat::operator=( const WrongCat &rhs )
{
    std::cout << "WrongCat assignment operator called" << std::endl;
    _type = rhs._type;
    return *this;
}

WrongCat::~WrongCat( void )
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void    WrongCat::makeSound( void ) const
{
    std::cout << "Sound of a wrong Cat!" << std::endl;
}