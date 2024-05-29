#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <iomanip>

class Zombie {

public:

    Zombie(std::string ZombieName);
    Zombie(void);
    ~Zombie(void);
    void    announce(void);
    void    setName(std::string ZombieName);

private:

    std::string name;

};

Zombie* zombieHorde( int N, std::string name );

#endif