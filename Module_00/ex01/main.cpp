#include "PhoneBook.hpp"

int main()
{
    std::string cmd;
    PhoneBook newPhonebook;

    std::cout << "Enter ADD, SEARCH or EXIT" << std::endl;
    while (std::getline(std::cin, cmd))
    {
        if (cmd == "ADD")
            newPhonebook.addcontact();
        else if (cmd == "SEARCH")
            newPhonebook.getPhoneBook();
        else if (cmd == "EXIT")
            break;
        else
            std::cout << "Enter ADD, SEARCH or EXIT" << std::endl;
    }
    return (0);
}