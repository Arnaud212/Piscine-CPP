#ifndef SHRUBBERYCREATIONTFORM_HPP
#define SHRUBBERYCREATIONTFORM_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &rhs);
        ~ShrubberyCreationForm();

        void execute(const Bureaucrat &executor) const;

    private:
        std::string _target;      
};

#endif