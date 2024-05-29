#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"

class Cat : public AAnimal
{
    public:
        Cat( void );
        Cat( const Cat &rhs );
        Cat& operator=( const Cat &rhs );
        ~Cat( void );

        void    makeSound( void ) const;

    private:
        Brain *_brain;
    
};

#endif