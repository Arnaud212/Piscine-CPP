#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal
{
    public:
        Animal( void );
        Animal( std::string type );
        Animal( const Animal &rhs );
        Animal& operator=( const Animal &rhs );
        virtual ~Animal( void );

        std::string     getType( void ) const;
        virtual void    makeSound( void ) const;


    protected:
        std::string _type;

};

#endif