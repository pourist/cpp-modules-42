#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


class Intern
{ 
    public:
        Intern();
        ~Intern();
        Intern(const Intern& src);

        Intern  &operator=(const Intern& src);

        AForm*   PPForm(std::string target);
        AForm*   RRForm(std::string target);
        AForm*   SCForm(std::string target);

        AForm*   makeForm(std::string name, std::string target);

        class   FormNotFoundException: public std::exception
        {
            virtual const char* what() const throw();
        };
};




#endif