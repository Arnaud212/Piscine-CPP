#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat( void );
        Cat( const Cat &rhs );
        Cat& operator=( const Cat &rhs );
        virtual ~Cat( void );

        void    makeSound( void ) const;

    private:
        Brain *_brain;
    
};

#endif