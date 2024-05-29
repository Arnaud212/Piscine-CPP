#include "Fixed.hpp"

Fixed::Fixed( void ) : _nb(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int n ) : _nb( n << _fractBits)
{
    //std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float n ) : _nb( roundf( n * (1 << _fractBits)))
{
    //std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &rhs )
{
    //std::cout << "Copy constructor called" << std::endl;
    //setRawBits(rhs.getRawBits());
    *this = rhs;
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=( const Fixed &rhs )
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &rhs )
		this->_nb = rhs.getRawBits();
	return *this;
}

int     Fixed::getRawBits( void ) const
{
//    std::cout << "getRawBits member function called" << std::endl;
    return this->_nb;
}

void    Fixed::setRawBits( int const raw)
{
    this->_nb = raw;
}

float   Fixed::toFloat( void ) const
{
    return static_cast<float>( this->getRawBits() ) / ( 1 << _fractBits);
}

int     Fixed::toInt( void ) const
{
    return this->_nb >> _fractBits;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return (o);
}

//----------------- Comparison operators -----------------//

bool    Fixed::operator>( const Fixed &rhs ) const
{
    return this->getRawBits() > rhs.getRawBits();
}

bool    Fixed::operator<( const Fixed &rhs ) const
{
    return this->getRawBits() < rhs.getRawBits();
}

bool    Fixed::operator>=( const Fixed &rhs ) const
{
    return this->getRawBits() >= rhs.getRawBits();
}

bool   Fixed::operator<=( const Fixed &rhs ) const {
    return this->getRawBits() <= rhs.getRawBits();
}

bool  Fixed::operator==( const Fixed &rhs ) const
{
    return this->getRawBits() == rhs.getRawBits();
}

bool    Fixed::operator!=( const Fixed &rhs ) const
{
    return this->getRawBits() != rhs.getRawBits();
}

//------------------ Arithmetic operators ------------------//

Fixed   Fixed::operator+( const Fixed &rhs ) const
{
    return Fixed( this->toFloat() + rhs.toFloat() );
}

Fixed   Fixed::operator-( const Fixed &rhs ) const
{
    return Fixed( this->toFloat() - rhs.toFloat() );
}

Fixed   Fixed::operator*( const Fixed &rhs ) const
{
    return Fixed( this->toFloat() * rhs.toFloat() );
}

Fixed   Fixed::operator/( const Fixed &rhs ) const
{
    return Fixed( this->toFloat() / rhs.toFloat() );
}

//------------------ Increment/Decrement operators ------------------//

Fixed&   Fixed::operator++( void )
{
    ++this->_nb;
    return *this;
}

Fixed   Fixed::operator++( int )
{
    Fixed tmp( *this );
    tmp._nb = this->_nb++;
    return tmp;
}

Fixed& Fixed::operator--( void )
{
    --this->_nb;
    return *this;
}

Fixed Fixed::operator--( int )
{
    Fixed tmp( *this );
    tmp._nb = this->_nb--;
    return tmp;
}

//----------------------- Max and Min ----------------------//

Fixed& Fixed::min( Fixed &a, Fixed &b )
{
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b )
{
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

Fixed& Fixed::max( Fixed &a, Fixed &b )
{
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b )
{
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}