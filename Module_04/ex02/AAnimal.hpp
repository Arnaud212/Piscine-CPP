#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include "Brain.hpp"

class AAnimal
{
    public:
        AAnimal( void );
        AAnimal( std::string type );
        AAnimal( const AAnimal &rhs );
        AAnimal& operator=( const AAnimal &rhs );
        virtual ~AAnimal( void );

        std::string     getType( void ) const; 
        virtual void    makeSound( void ) const = 0;;

    protected:
        std::string _type;
    
};

#endif