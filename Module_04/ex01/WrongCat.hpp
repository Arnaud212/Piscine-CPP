#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat( void );
        WrongCat( const WrongCat &rhs );
        WrongCat& operator=( const WrongCat &rhs );
        ~WrongCat( void );

        void    makeSound( void ) const;

    private:
    
};

#endif