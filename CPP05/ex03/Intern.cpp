#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern( const Intern& src)
{
    *this = src;
}

Intern& Intern::operator=(const Intern& src)
{
    (void)src;
    return (*this);
}

AForm*   Intern::PPForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm*   Intern::RRForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm*   Intern::SCForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm*   Intern::makeForm(std::string name, std::string target)
{
    std::string forms[3] = {"presidential pardon", "robotomy request",
                            "shrubbery creation"};
    AForm*    (Intern::*functions[3])(std::string) = {&Intern::PPForm, 
        &Intern::RRForm, &Intern::SCForm};
    
    for (int i = 0; i < 3; i++)
    {
        if (name == forms[i])
        {
            std::cout << "Intern creates " << forms[i] << std::endl;
            return ((this->*functions[i])(target));
        }
    }
    throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw()
{
    return ("Intern could not find the form.");
}