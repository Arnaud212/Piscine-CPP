#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"

class Dog : public AAnimal
{
    public:
        Dog( void );
        Dog( const Dog &rhs );
        Dog& operator=( const Dog &rhs );
        ~Dog( void );

        void    makeSound( void ) const;

    private:
        Brain *_brain;
};

#endif