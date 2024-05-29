#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{

    public:

        Fixed( void );
        Fixed( const Fixed &rhs );
        Fixed& operator=( const Fixed &rhs);
        ~Fixed( void );

        int     getRawBits( void ) const;
        void    setRawBits( int const raw );

    private:

        int              _nb;
        static const int _fractBits = 8;

};


#endif