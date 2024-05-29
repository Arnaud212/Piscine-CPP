#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"

class Intern
{
    public:
        Intern();
        Intern( const Intern &rhs);
        Intern& operator=(const Intern &rhs);
        ~Intern();

        Form*   makeForm( std::string name, std::string target);

        class Error : public std::exception
    {
        virtual const char* what() const throw();
    };

};

#endif