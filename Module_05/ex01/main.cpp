#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{
    Bureaucrat Asselineau("Asselineau", 9);
    Bureaucrat Pecresse("Pecresse", 140);
    Asselineau.incrementGrade();
    std::cout << "increment: " << Asselineau << std::endl;
    Asselineau.decrementGrade();
    std::cout << "decrement: " << Asselineau << std::endl;

    std::cout << std::endl;
    try
    {
        Bureaucrat Castex("Castex", -1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat Veran("Veran", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat Macron("Macron", 149);
        Macron.incrementGrade();
        std::cout << Macron << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat Sarko("Sarko", 150);
        std::cout << Sarko << std::endl;
        Sarko.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    //

    Form A1("A1", 19, 25);
    Form A2("A2", 48, 48);
    Form A3("A3",139, 22);

    std::cout << Asselineau << std::endl;
    std::cout << Pecresse << std::endl;
    std::cout << A1 << std::endl;
    std::cout << A2 << std::endl;
    std::cout << A3 << std::endl;


    try 
    {
        Asselineau.signForm(A1);
    }
    catch (std::exception &e) 
    {
        std::cout << "Exception caught: "<< e.what() << std::endl;
    }

    try 
    {
        Pecresse.signForm(A2);
    }
    catch (std::exception &e) 
    {
        std::cout << "Exception caught: "<< e.what() << std::endl;
    }

    try 
    {
        Pecresse.signForm(A3);
    }
    catch (std::exception &e) 
    {
        std::cout << "Exception caught: "<< e.what() << std::endl;
    }

    Pecresse.incrementGrade();

    try 
    {
        Pecresse.signForm(A3);
    }
    catch (std::exception &e) 
    {
        std::cout << "Exception caught: "<< e.what() << std::endl;
    }

	return (0);	
}