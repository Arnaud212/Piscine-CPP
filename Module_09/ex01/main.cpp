#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./RPN <RPN calcul>" << std::endl;
        return (1);
    }
    RPN rpn;
    rpn.expression(av[1]);
    return (0);
}