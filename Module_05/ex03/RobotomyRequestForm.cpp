#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), _target("Wood planking")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) : Form(rhs), _target(rhs._target)
{
    *this = rhs;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm &rhs)
{
    (void)rhs;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void    RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if ( executor.getGrade() > this->getGradeToExecute() )
        throw Form::GradeTooLowException();
    else {
        static int  i;
        if ( i % 2 == 0 )
            std::cout << "BZZZZZZZ! " << _target << " has been robotomized!" << std::endl;
        else
            std::cout << "Robotomy failed! " << _target << " is still alive." << std::endl;
        i++;
    }
}