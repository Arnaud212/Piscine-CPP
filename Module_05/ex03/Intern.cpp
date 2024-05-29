#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{}

Intern::Intern( const Intern &rhs)
{
    *this = rhs;
}

Intern& Intern::operator=(const Intern &rhs)
{
    (void)rhs;
    return *this;
}

Intern::~Intern()
{}

Form*   Intern::makeForm(std::string name, std::string target)
{
     std::string formNames[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };
    Form*    forms[3] = {
        new RobotomyRequestForm( target ),
        new PresidentialPardonForm( target ),
        new ShrubberyCreationForm( target )
    };
    for ( int i(0); i < 3; i++ ) 
    {
        if ( name == formNames[i] ) 
        {
            std::cout << "Intern creates " << name << std::endl;
            for (int j(0); j < 3; j++)
            {
                if (j != i)
                    delete forms[j];
            }
            return forms[i];
        }
    }
    for (int j(0); j < 3; j++)
    {
        delete forms[j];
    }
    throw Error();
        return NULL;
}

const char *Intern::Error::what() const throw()
{
	return ("Error : Intern cannot create this form\n");
}

