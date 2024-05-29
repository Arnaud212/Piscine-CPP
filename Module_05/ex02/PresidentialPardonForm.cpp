#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), _target("A prisoner")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs) : Form(rhs), _target(rhs._target)
{
    *this = rhs;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm &rhs)
{
    (void)rhs;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void    PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
     if ( executor.getGrade() > this->getGradeToExecute() )
        throw Form::GradeTooLowException();
    else {
        std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
}