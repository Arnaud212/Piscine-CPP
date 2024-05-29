#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <set>

class PhoneBook
{
public:
    
    PhoneBook();
    ~PhoneBook();
    void addcontact();
    void getPhoneBook();

private:

    Contact contact[8];
    int     length;

    void    getIndexContact();
};

#endif