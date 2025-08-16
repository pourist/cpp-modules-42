#include "AForm.hpp"
#include "Bureaucrat.h"

AForm::AForm(): Name("Unnamed"), is_signed(false), sign_grade(50), exec_grade(10)
{
}

AForm::AForm(std::string _Name, int _sign_grade, int   _exec_grade): Name(_Name), 
                     sign_grade(_sign_grade), exec_grade(_exec_grade)
{
    this->is_signed = false;
	if (sign_grade > MIN_GRADE || exec_grade > MIN_GRADE)
		throw AForm::GradeTooLowException();
	else if (sign_grade < MAX_GRADE || exec_grade < MAX_GRADE)
		throw AForm::GradeTooHighException();
}

AForm::~AForm(){
}

AForm::AForm(const AForm& src): Name(src.Name), 
                        sign_grade(src.sign_grade), exec_grade(src.exec_grade)
{
}

AForm    &AForm::operator=(const AForm& src)
{
    //useless as const
    (void)src;
    return(*this);
}

std::string    AForm::getName() const
{
    return(this->Name);
}

bool    AForm::getIsSigned() const
{
    return(this->is_signed);
}

int   AForm::getSignGrade() const
{
    return(this->sign_grade);
}

int   AForm::getExecGrade() const
{
    return(this->exec_grade);
}

void    AForm::beSigned(Bureaucrat& bureaucrat)
{
    if (this->is_signed)
        throw AForm::AlreadySignedException();
    if (this->sign_grade >= bureaucrat.getGrade())
        this->is_signed = true;
    else
        throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("Action denied. Form is unsigned.");
}

const char* AForm::AlreadySignedException::what() const throw()
{
	return ("Action not required. Form is already signed.");
}

const char* AForm::ExecutionGradeTooLowException::what() const throw()
{
    return "Execution failed. Insufficient grade.";
}

void    AForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
    throw   NotSignedException();
    if (this->getExecGrade() < executor.getGrade())
    throw   ExecutionGradeTooLowException();
    executeConcrete();
}

std::ostream&   operator<<(std::ostream &o, const AForm& form)
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