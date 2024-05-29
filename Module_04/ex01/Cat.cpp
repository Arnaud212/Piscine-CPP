#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
    std::cout << "Cat constructor called" << std::endl;
    try
    {
        _brain = new Brain();
    }
    catch(const std::bad_alloc& e)
    {
        std::cout << "Memory failed allocation : " << e.what() << std::endl;
    }
    
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
    _brain = new Brain( *rhs._brain );
    return *this;
}

Cat::~Cat( void )
{
    delete _brain;
    std::cout << "Cat destructor called" << std::endl;
}

void    Cat::makeSound( void ) const
{
    std::cout << "Meow Meow!" << std::endl;
}