#include "Form.hpp"
#include "Bureaucrat.h"

Form::Form(): Name("Unnamed"), is_signed(false), sign_grade(50), exec_grade(10)
{
}

Form::Form(std::string _Name, int _sign_grade, int   _exec_grade): Name(_Name), 
                     sign_grade(_sign_grade), exec_grade(_exec_grade)
{
    this->is_signed = false;
	if (sign_grade > MIN_GRADE || exec_grade > MIN_GRADE)
		throw Form::GradeTooLowException();
	else if (sign_grade < MAX_GRADE || exec_grade < MAX_GRADE)
		throw Form::GradeTooHighException();
}

Form::~Form(){
}

Form::Form(const Form& src): Name(src.Name), 
                        sign_grade(src.sign_grade), exec_grade(src.exec_grade)
{
}

Form    &Form::operator=(const Form& src)
{
    //useless as const
    (void)src;
    return(*this);
}

std::string    Form::getName() const
{
    return(this->Name);
}

bool    Form::getIsSigned() const
{
    return(this->is_signed);
}

int   Form::getSignGrade() const
{
    return(this->sign_grade);
}

int   Form::getExecGrade() const
{
    return(this->exec_grade);
}

void    Form::beSigned(Bureaucrat& bureaucrat)
{
    if (this->is_signed)
        throw Form::AlreadySignedException();
    if (this->sign_grade >= bureaucrat.getGrade())
        this->is_signed = true;
    else
        throw Form::GradeTooLowException();
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* Form::AlreadySignedException::what() const throw()
{
	return ("Action not required. Form is already signed.");
}

std::ostream&   operator<<(std::ostream &o, const Form& form)
{
    if (form.getIsSigned())
        o << std::boolalpha << "Form name: " << Blue << form.getName() 
        << Reset
        << "\nGrade to sign: " << Green << form.getSignGrade() << Reset
        << "\nGrade to execute: " << Green << form.getExecGrade() << Reset 
        << "\nStatus: "<< Green << "signed" 
        << Reset << std::endl;
    else
        o << std::boolalpha << "Form name: " << Blue << form.getName()
        << Reset
        << "\nGrade to sign: " << Green << form.getSignGrade() << Reset 
        << "\nGrade to execute: " << Green << form.getExecGrade() << Reset 
        << "\nStatus: "<< Red << "not signed" 
        << Reset << std::endl;
    return (o);
}