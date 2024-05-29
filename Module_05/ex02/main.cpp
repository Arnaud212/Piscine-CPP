#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void )
{
    
    {
        PresidentialPardonForm pre("A1");
        Bureaucrat Conrad("Conrad", 1);

        std::cout << Conrad << std::endl;
        std::cout << pre << std::endl;
        Conrad.signForm(pre);
        Conrad.executeForm(pre);
    }

    std::cout  << std::endl << "|------------------------------------------|" << std::endl << std::endl;

    {
        PresidentialPardonForm pre("A2");
        Bureaucrat Conrad("Conrad", 10);

        std::cout << Conrad << std::endl;
        std::cout << pre << std::endl;
        Conrad.signForm(pre);
        Conrad.executeForm(pre);
    }

    std::cout  << std::endl << "|-----------------------------------------|" << std::endl << std::endl;

    {
        PresidentialPardonForm pre("A3");
        Bureaucrat Conrad("Conrad", 1);

        std::cout << Conrad << std::endl;
        std::cout << pre << std::endl;
        pre.beSigned(Conrad);
        pre.execute(Conrad);
    }

    std::cout  << std::endl << "|-------------------------------------------|" << std::endl << std::endl;

    {
        PresidentialPardonForm pre("A4");
        Bureaucrat Conrad("Conrad", 1);

        std::cout << Conrad << std::endl;
        std::cout << pre << std::endl;
        Conrad.executeForm(pre);
    }

    std::cout  << std::endl << "|---------------------------------------------|" << std::endl << std::endl;

    {
        RobotomyRequestForm rob("A5");
        Bureaucrat Conrad("Conrad", 1);

        std::cout << Conrad << std::endl;
        std::cout << rob << std::endl;
        Conrad.signForm(rob);
        Conrad.executeForm(rob);
    }

    std::cout  << std::endl << "|----------------------------------------------|" << std::endl << std::endl;

    {
        RobotomyRequestForm rob("A6");
        Bureaucrat Conrad("Conrad", 1);

        std::cout << Conrad << std::endl;
        std::cout << rob << std::endl;
        Conrad.signForm(rob);
        Conrad.executeForm(rob);
    }

    std::cout  << std::endl << "|-------------------------------------------------|" << std::endl << std::endl;

    {
        RobotomyRequestForm rob("A7");
        Bureaucrat Conrad("Conrad", 1);

        std::cout << Conrad << std::endl;
        std::cout << rob << std::endl;
        Conrad.signForm(rob);
        Conrad.executeForm(rob);
    }

    std::cout  << std::endl << "|---------------------------------------------------|" << std::endl << std::endl;

    {
        ShrubberyCreationForm shr("A8");
        Bureaucrat Conrad("Conrad", 1);

        std::cout << Conrad << std::endl;
        std::cout << shr << std::endl;
        Conrad.signForm(shr);
        Conrad.executeForm(shr);
    }

    std::cout  << std::endl << "|---------------------------------------------------|" << std::endl << std::endl;

    {
        ShrubberyCreationForm shr("A9");
        Bureaucrat Conrad("Conrad", 1);

        std::cout << Conrad << std::endl;
        std::cout << shr << std::endl;
        Conrad.signForm(shr);
        Conrad.executeForm(shr);
    }

    std::cout  << std::endl << "|---------------------------------------------------|" << std::endl << std::endl;

    {
        ShrubberyCreationForm shr("A10");
        Bureaucrat Conrad("Conrad", 142);

        std::cout << Conrad << std::endl;
        std::cout << shr << std::endl;
        Conrad.signForm(shr);
        Conrad.executeForm(shr);
    }
    

	return (0);
}