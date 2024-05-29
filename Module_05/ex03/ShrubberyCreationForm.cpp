#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), _target("Garden")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs) : Form(rhs), _target(rhs._target)
{
    *this = rhs;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm &rhs)
{
    (void)rhs;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void    ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if ( this->getSigned() == false )
        throw Form::NotSignedException();
    else if ( executor.getGrade() > this->getGradeToExecute() ) {
        throw Form::GradeTooLowException();
    }

    std::ofstream outfile;
    std::string file( _target + "_shrubbery" );
    outfile.open(file.c_str());
    outfile << "                      ___" << std::endl;
    outfile << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
    outfile << "             ,-'          __,,-- \\" << std::endl;
    outfile << "           ,\'    __,--\"\"\"\"dF      )" << std::endl;
    outfile << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
    outfile << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
    outfile << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
    outfile << "     (     ,-'                  `." << std::endl;
    outfile << "      `._,'     _   _             ;" << std::endl;
    outfile << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
    outfile << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
    outfile << "        `--\'   \"Hb  HH  dF\"" << std::endl;
    outfile << "                \"Hb HH dF" << std::endl;
    outfile << "                 \"HbHHdF" << std::endl;
    outfile << "                  |HHHF" << std::endl;
    outfile << "                  |HHH|" << std::endl;
    outfile << "                  |HHH|" << std::endl;
    outfile << "                  |HHH|" << std::endl;
    outfile << "                  |HHH|" << std::endl;
    outfile << "                  dHHHb" << std::endl;
    outfile << "                .dFd|bHb.               o" << std::endl;
    outfile << "      o       .dHFdH|HbTHb.          o /" << std::endl;
    outfile << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
    outfile << "##########################################" << std::endl;
    outfile.close();
}