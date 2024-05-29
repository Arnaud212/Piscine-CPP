#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat 
{
    public:
        Bureaucrat( void );
        explicit Bureaucrat( const std::string name );
        explicit Bureaucrat( int grade );
        Bureaucrat( const std::string name, int grade );
        Bureaucrat( const Bureaucrat &rhs );
        Bureaucrat& operator=( const Bureaucrat &rhs );
        ~Bureaucrat( void );

        /*---------------Function-------------------*/

        void        signForm(Form& form);

        /*----------------Getter-------------------*/
        
        std::string getName() const;
        int         getGrade() const;

        /*----------------Grade(++--)--------------*/
        
        void        incrementGrade();
        void        decrementGrade();

        /*----------Exception class----------------*/
        
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return "Grade too high"; }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return "Grade too low"; }
        };
    
    private:
        const std::string   _name;
        int                 _grade;

};

/*----------------------------Insertion---------------*/

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs );

#endif