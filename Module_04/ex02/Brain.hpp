#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

class Brain
{
    public:
        Brain( void );
        ~Brain( void );
        Brain( const Brain &rhs );
        Brain& operator=( const Brain &rhs );

    private:
        std::string _ideas[100];

};

#endif