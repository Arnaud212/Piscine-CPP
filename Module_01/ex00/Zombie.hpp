#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <iomanip>
class Zombie {

public:

    Zombie(std::string ZombieName);
    ~Zombie(void);
    void    announce(void);

private:

    std::string name;

};

Zombie* newZombie( std::string name );
void    randomChump( std::string name );

#endif
