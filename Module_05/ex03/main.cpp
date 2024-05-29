#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void )
{
    Intern someRandomIntern;
    Form *rob;
    Form *presid;
    Form *shrub;
    Bureaucrat Fry("Fry", 3);
    Bureaucrat Bender("Bender", 24);
    Bureaucrat Zoidberg("Zoidberg", 72);

    try
    {
        rob = someRandomIntern.makeForm("robotomy request", "A1");
        //rob = someRandomIntern.makeForm("FAKE", "A1");
        Fry.signForm(*rob);
        Fry.executeForm(*rob);
        std::cout << std::endl;
        presid = someRandomIntern.makeForm("presidential pardon", "A2");
        Bender.signForm(*presid);
        Bender.executeForm(*presid);
        std::cout << std::endl;
        shrub = someRandomIntern.makeForm("shrubbery creation", "A3");
        Zoidberg.signForm(*shrub);
        Zoidberg.executeForm(*shrub);
        delete rob;
        delete presid;
        delete shrub;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what();
    }

	return (0);	
}