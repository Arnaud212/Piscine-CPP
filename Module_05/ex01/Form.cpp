#include "Form.hpp"

Form::Form(const std::string& name, int gradeToSign ) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(0), _signed(false)
{
    if (gradeToSign < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false)
{
    if (gradeToSign < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &rhs) : _name(rhs.getName()), _gradeToSign(rhs.getGradeToSign()), _gradeToExecute(rhs.getGradeToExecute()), _signed(false)
{
    *this = rhs;
}

Form& Form::operator=(const Form &rhs)
{
    _signed = rhs.getSigned();
    return *this;
}

Form::~Form(void)
{}

/*-------------------------Function-------------------------*/

void        Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    _signed = true;
}

/*--------------------------Getter--------------------------*/

std::string Form::getName() const
{
    return _name;
}

bool        Form::getSigned() const
{
    return _signed;
}

int         Form::getGradeToSign() const
{
    return _gradeToSign;
}

int         Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

/*---------------------------Operator-------------------------*/

std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
    o << "------------Form Info-------------" << std::endl;
    o << "Form name : " << rhs.getName() << std::endl
      << "Grade to sign : " << rhs.getGradeToSign() << std::endl
      << "Grade to execute : " << rhs.getGradeToExecute() << std::endl;
    return o; 
}