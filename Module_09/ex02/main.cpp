# include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac != 1)
    {
        PmergeMe nbs;
        nbs.input(ac, av);
    }
    else
        std::cout << "Error: No argument" << std::endl;
    return (0);
}