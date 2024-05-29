#include "Dog.hpp"

Dog::Dog( void ) : AAnimal( "Dog" )
{
    std::cout << "Dog constructor called" << std::endl;
    try
    {
        _brain = new Brain();
    }
    catch(const std::bad_alloc& e)
    {
        std::cout << "Memory failed allocation : " << e.what() << std::endl;
    }
    
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
    _brain = new Brain (*rhs._brain );
    return *this;
}

Dog::~Dog( void )
{
    delete _brain;
    std::cout << "Dog destructor called" << std::endl;
}

void    Dog::makeSound( void ) const
{
    std::cout << "Woof Woof!" << std::endl;
}