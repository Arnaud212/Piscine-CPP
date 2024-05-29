#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Unknow"), _grade(150)
{}

Bureaucrat::Bureaucrat( const std::string name ) : _name(name), _grade(150)
{}

Bureaucrat::Bureaucrat( int grade ) : _name("Unknow"), _grade(grade)
{
     if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( const std::string name, int grade ) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    //std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &rhs )
{
    *this = rhs;
   // std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat &rhs)
{
    _grade = rhs._grade;
    //std::cout << "Bureaucrat assignment operator called" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat( void )
{
    //std::cout << "Bureaucrat destructor called" << std::endl;
}

/*------------------------Getter----------------------*/

std::string     Bureaucrat::getName() const
{
    return _name;
}

int             Bureaucrat::getGrade() const
{
    return _grade;
}

/*------------------------Grade(++--)-----------------*/

void            Bureaucrat::incrementGrade()
{
    if (_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void            Bureaucrat::decrementGrade()
{
    if (_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

/*------------------------Function------------------------*/

void            Bureaucrat::signForm(Form& form)
{
    try {
        form.beSigned(*this);
        std::cout << *this << " signed " << form.getName() << std::endl;
    } catch (Form::GradeTooLowException &e) {
        std::cout << _name << " coulnd't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

/*------------------------Insertion-----------------------*/

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs )
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return o;
}