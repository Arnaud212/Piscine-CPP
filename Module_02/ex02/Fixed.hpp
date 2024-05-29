#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>
# include <cstdio>

class Fixed
{

    public:

        Fixed( void );
        Fixed( const int n );
        Fixed( const float n );
        Fixed( const Fixed &rhs );
        Fixed& operator=( const Fixed &rhs);
        ~Fixed( void );

        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        
        float   toFloat( void ) const;
        int     toInt( void ) const;

        bool    operator>( const Fixed &rhs ) const;
        bool    operator<( const Fixed &rhs ) const;
        bool    operator>=( const Fixed &rhs ) const;
        bool    operator<=( const Fixed &rhs ) const;
        bool    operator==( const Fixed &rhs ) const;
        bool    operator!=( const Fixed &rhs ) const;

        Fixed   operator+( const Fixed &rhs ) const;
        Fixed   operator-( const Fixed &rhs ) const;
        Fixed   operator*( const Fixed &rhs ) const;
        Fixed   operator/( const Fixed &rhs ) const;
    
        Fixed&  operator++( void ); // prefix
        Fixed   operator++( int ); // postfix
        Fixed&  operator--( void ); // prefix
        Fixed   operator--( int ); // postfix

        static Fixed& min( Fixed &a, Fixed &b );
        static const Fixed& min( const Fixed &a, const Fixed &b );
        static Fixed& max( Fixed &a, Fixed &b );
        static const Fixed& max( const Fixed &a, const Fixed &b );
    
    private:

        int              _nb;
        static const int _fractBits = 8;

};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
