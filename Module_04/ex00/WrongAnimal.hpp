#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal( void );
        WrongAnimal( std::string type );
        WrongAnimal( const WrongAnimal &rhs );
        WrongAnimal& operator=( const WrongAnimal &rhs );
        ~WrongAnimal( void );

        std::string     getType( void ) const;
        void             makeSound( void ) const;


    protected:
        std::string _type;

};

#endif