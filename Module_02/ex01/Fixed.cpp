#include "Fixed.hpp"

Fixed::Fixed( void ) : _nb(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int n ) : _nb( n << _fractBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float n ) : _nb( roundf( n * (1 << _fractBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &rhs )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=( const Fixed &rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	_nb = rhs.getRawBits();
	return *this;
}

int     Fixed::getRawBits( void ) const
{
    return _nb;
}

void    Fixed::setRawBits( int const raw)
{
    _nb = raw;
}

float   Fixed::toFloat( void ) const
{
    return static_cast<float>( getRawBits() ) / ( 1 << _fractBits);
}

int     Fixed::toInt( void ) const
{
    return _nb >> _fractBits;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return o;
}
