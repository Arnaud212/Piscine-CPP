#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <iomanip>

class Contact {

public:

    Contact( void );
    ~Contact( void );
    void    savecontact();
    void    getContacts(int width, char sep);
    void    getContactInfo();

private:
    
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    std::string truncate(std::string name, int width);

};

#endif