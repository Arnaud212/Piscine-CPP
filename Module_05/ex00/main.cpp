#include "Bureaucrat.hpp"

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

}