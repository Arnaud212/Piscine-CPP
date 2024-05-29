#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>
# include <iomanip>

class Weapon {

public :

    Weapon(std::string weapon);
    Weapon(void);
    ~Weapon(void);
    const std::string& getType(void);
    void        setType(std::string type);

private :

    std::string _type;
};

#endif