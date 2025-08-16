#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string Name;
        bool    is_signed;
        const int   sign_grade;
        const int   exec_grade;
    public:
        Form();
        ~Form();
        Form(const Form& src);
        Form(std::string _name, int sign_grade, int   exec_grade);
        Form    &operator=(const Form& src);

        std::string    getName() const;
        bool    getIsSigned() const;
        int   getSignGrade() const;
        int   getExecGrade() const;


        void    beSigned(Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            const char* what() const throw();
        };
        class AlreadySignedException : public std::exception
        {
            const char* what() const throw();
        };
};

std::ostream&   operator<<(std::ostream &o, const Form& form);

#endif