#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;
    
    if (ac != 2)
    {
        std::cerr << "Error : you have to complain about a problem" << std::endl;
        return (0);
    }
    std::string input = av[1];
    harl.complain(input);
    return (0);
}