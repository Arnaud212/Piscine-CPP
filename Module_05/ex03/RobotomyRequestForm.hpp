#ifndef ROBOTOMYRREQUESTFORM_HPP
#define ROBOTOMYRREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm &rhs);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &rhs);
        ~RobotomyRequestForm();

        void execute(const Bureaucrat &executor) const;

    private:
        std::string _target;      
};

#endif