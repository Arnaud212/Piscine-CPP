#include "Zombie.hpp"

int main()
{
    std::cout << "zombieHord is set to 2 with the name Foo" << std::endl;
    {
        Zombie *firstHorde = zombieHorde(2, "Foo");
        for (int i = 0; i < 2; i++)
            firstHorde[i].announce();
        delete [] firstHorde;
    }
    std::cout << "zombieHord is set to 5 with the name Faa" << std::endl;
    {
        Zombie *secondHorde = zombieHorde(5, "Faa");
        for (int i = 0; i < 5; i++)
            secondHorde[i].announce();
        delete [] secondHorde;
    }
    return (0);
}