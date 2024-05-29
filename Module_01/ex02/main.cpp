#include <iostream>
#include <iomanip>

int main() 
{
    std::string brain       = "HI THIS IS BRAIN";
    std::string* stringPTR  = &brain;
    std::string& stringREF  = brain;

    std::cout << "The address of the string in memory is : " << &brain << std::endl;
    std::cout << "The address stored in stringPTR is : " << stringPTR << std::endl;
    std::cout << "The address stored in stringREF is : " << &stringREF << std::endl;

    std::cout << "The value of the string is : " << brain << std::endl;
    std::cout << "The value pointed to by stringPTR is : " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF is : " << stringREF << std::endl;
}