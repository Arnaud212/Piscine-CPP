#include "PhoneBook.hpp"

PhoneBook::PhoneBook() 
{
    this->length = 0;
    return;
}

void    PhoneBook::addcontact()
{
    Contact newcontact;

    newcontact.savecontact();
    this->contact[length % 8] = newcontact;
    length++;
    return;
}

void    PhoneBook::getIndexContact()
{
    int index;

    std::cout << "Enter the index of the contact to display : ";
    std::cin >> index;
    if (std::cin.fail())
	{
		std::cin.clear();
		//std::cin.ignore(10000, '\n');
		std::cout << "You have to entered a number" << std::endl;
		return;
	}
	if (index < 0 || index > length - 1 || index > 7)
    {
		std::cout << "Index out of range\n";
        return;
    }
    contact[index].getContactInfo();
}

void    PhoneBook::getPhoneBook()
{
    int width = 10;
    char sep = '|';
    int index = 0;

    std::cout << std::setw(width) << "Index" << sep;
    std::cout << std::setw(width) << "First Name" << sep;
    std::cout << std::setw(width) << "Last Name" << sep;
    std::cout << std::setw(width) << "Nickname" << std::endl;
    while (index < length && index < 8)
    {
        std::cout << std::setw(width) << index << sep;
        contact[index].getContacts(width, sep);
        index++;
    }
    getIndexContact();
}


PhoneBook::~PhoneBook( void )
{
    return;
}

