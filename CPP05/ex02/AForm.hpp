#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"
# include <fstream>

class Bureaucrat;

class AForm
{
    private:
        const std::string Name;
        bool    is_signed;
        const int   sign_grade;
        const int   exec_grade;
    public:
        AForm();
        virtual ~AForm();
        AForm(const AForm& src);
        AForm(std::string _name, int sign_grade, int   exec_grade);
        AForm    &operator=(const AForm& src);

        std::string    getName() const;
        bool    getIsSigned() const;
        int     getSignGrade() const;
        int     getExecGrade() const;


        void    beSigned(Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            const char* what() const throw();
        };
        class NotSignedException : public std::exception
        {
            const char* what() const throw();
        };
        class AlreadySignedException : public std::exception
        {
            const char* what() const throw();
        };
        class ExecutionGradeTooLowException : public std::exception
        {
            const char* what() const throw();
        };

        void    execute(Bureaucrat const & executor) const;
        virtual void    executeConcrete() const = 0;
};

std::ostream&   operator<<(std::ostream &o, const AForm& form);

#endif