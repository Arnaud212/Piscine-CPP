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
        virtual ~Form( void );

        /*-------------------Function--------------------*/

        void            beSigned( const Bureaucrat& bureaucrat );
        virtual void    execute(const Bureaucrat& executor) const = 0;

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

        class NotSignedException : public std::exception 
        {
            public:
                const char* what() const throw() { return "Form not signed"; }
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