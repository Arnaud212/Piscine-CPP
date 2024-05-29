#include <iostream>
#include "Contact.hpp"

void    Contact::savecontact()
{
    std::cout << "New contact :" << std::endl;
    std::cout << "First Name : ";
    std::getline(std::cin, this->firstName);
    while (firstName.length() == 0)
        std::getline(std::cin, this->firstName);
    std::cout << "Last Name : ";
    std::getline(std::cin, this->lastName);
    while (lastName.length() == 0)
        std::getline(std::cin, this->lastName);
    std::cout << "Nickname : ";
    std::getline(std::cin, this->nickname);
    while (nickname.length() == 0)
        std::getline(std::cin, this->nickname);
    std::cout << "Phone Number : ";
    std::getline(std::cin, this->phoneNumber);
    while (phoneNumber.length() == 0)
        std::getline(std::cin, this->phoneNumber);
    std::cout << "Darkest Secret : ";
    std::getline(std::cin, this->darkestSecret);
    while (darkestSecret.length() == 0)
        std::getline(std::cin, this->darkestSecret);
    std::cout << "Enter ADD, SEARCH or EXIT" << std::endl;
    return;
}

std::string     Contact::truncate(std::string name, int width)
{
    if ((int)name.size() <= width)
        return (name);
    else   
    {
        return (name.substr(0, 9) + ".");
    }
}

void    Contact::getContacts(int width, char sep)
{
    std::cout << std::setw(width) << truncate(this->firstName, width) << sep;
    std::cout << std::setw(width) << truncate(this->lastName, width) << sep;
    std::cout << std::setw(width) << truncate(this->nickname, width) << std::endl;
}

void    Contact::getContactInfo()
{
    std::cout << "First Name : " << firstName << std::endl;
    std::cout << "Last Name : " << lastName << std::endl;
    std::cout << "Nickname : " << nickname << std::endl;
    std::cout << "Phone Number : " << phoneNumber << std::endl;
    std::cout << "Darkest Secret : " << darkestSecret << std::endl;
}

Contact::Contact( void ) 
{
    return;
}

Contact::~Contact( void )
{
    return;
}