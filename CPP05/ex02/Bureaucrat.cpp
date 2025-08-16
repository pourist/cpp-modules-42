#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): Name("Unnamed"), grade(MIN_GRADE)
{
}

Bureaucrat::Bureaucrat(std::string _Name, int grade): Name(_Name)
{
	if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& src): Name(src.Name), grade(src.grade)
{
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat& src) // Name is const, assignment operator use is not valid
{
	if (this != &src)
	{
		this->grade = src.grade;
	}
	return (*this);
}

void	Bureaucrat::increment(int inc_num)
{
	if (this->grade - inc_num <= 0)
		throw Bureaucrat::GradeTooHighException();
	this->grade -= inc_num;
}

void	Bureaucrat::decrement(int dec_num)
{
	if (this->grade + dec_num > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade += dec_num;
}

std::string	Bureaucrat::getName() const
{
	return (Name);
}

int	Bureaucrat::getGrade() const
{
	return (grade);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& B)
{
	os << Blue << B.getName() << Reset 
	<< ", bureaucrat grade " << Yellow << B.getGrade()
	<< Reset << ".\n" ;
	return (os);
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << Green << " signed " << Reset 
		<< form.getName() << "." << std::endl; 
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << Red << " couldn't sign " << Reset 
		<< form.getName() << ":" << std::endl; 
		std::cerr << e.what() << '\n';
	}
}
