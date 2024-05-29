#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog( void );
        Dog( const Dog &rhs );
        Dog& operator=( const Dog &rhs );
        virtual ~Dog( void );

        void    makeSound( void ) const;

    private:
        Brain *_brain;
};

#endif