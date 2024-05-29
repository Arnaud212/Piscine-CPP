#include "Fixed.hpp"

Fixed::Fixed( void ) : _nb(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &rhs )
{
    std::cout << "Copy constructor called" << std::endl;
    setRawBits(rhs.getRawBits());
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=( const Fixed &rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	_nb = rhs.getRawBits();
	return *this;
}

int     Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _nb;
}

void    Fixed::setRawBits( int const raw)
{
    _nb = raw;

}
