#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form( const std::string& name, int gradeToSign );
        Form( const std::string& name, int gradeToSign, int gradeToExecute );
        Form( const Form &rhs );
        Form& operator=( const Form &rhs );
        ~Form( void );

        /*-------------------Function--------------------*/

        void        beSigned( const Bureaucrat& bureaucrat );

        /*--------------------Getter--------------------*/

        std::string getName() const;
        bool        getSigned() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;

        /*----------------Exceptions class----------------*/
        
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw() { return "Grade too high"; }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw() { return "Grade too low"; }
        };

    private:
        const std::string   _name;
        const int           _gradeToSign;
        const int           _gradeToExecute;
        bool                _signed;

};

/*------------------------------Operator-------------------------*/

std::ostream &operator<<(std::ostream &o, Form const &rhs );

#endif