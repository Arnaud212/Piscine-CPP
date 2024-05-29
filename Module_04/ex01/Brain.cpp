#include "Brain.hpp"

Brain::Brain( void ) 
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain( const Brain &rhs )
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = rhs;
}

Brain& Brain::operator=( const Brain &rhs )
{
    std::cout << "Brain assignment operator called" << std::endl;
    if ( this != &rhs )
    {
        for ( int i = 0; i < 100; i++ )
        {
            this->_ideas[i] = rhs._ideas[i];
        }
    }
    return *this;
}

Brain::~Brain( void )
{
    std::cout << "Brain destructor called" << std::endl;
}