#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat( const Cat &rhs )
{
    std::cout << "Cat copy constructpr called" << std::endl;
    *this = rhs;
}

Cat& Cat::operator=( const Cat &rhs )
{
    std::cout << "Cat assignment operator called" << std::endl;
    _type = rhs._type;
    return *this;
}

Cat::~Cat( void )
{
    std::cout << "Cat destructor called" << std::endl;
}

void    Cat::makeSound( void ) const
{
    std::cout << "Meow Meow!" << std::endl;
}