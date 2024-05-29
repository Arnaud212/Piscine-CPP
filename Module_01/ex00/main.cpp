#include "Zombie.hpp"

int main()
{
    std::cout << "Creating a new Zombie Foo with the first method :" << std::endl;
    
        Zombie Foo("Foo");
        Foo.announce();
    
    std::cout << "Creating a new Zombie Faa with the function newZombie : " << std::endl;
    
        Zombie* Faa = newZombie("Faa");
        Faa->announce();
        delete Faa;
    
    std::cout << "Creating a new Zombie Fii with the randomChump function : " << std::endl;
    
        randomChump("Fii");
    
    return (0);
}