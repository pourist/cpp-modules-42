#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string _target);
        ShrubberyCreationForm(const ShrubberyCreationForm& src);
        ShrubberyCreationForm   &operator=(const ShrubberyCreationForm& src);

        std::string getTarget() const;

        void    executeConcrete() const;
};

#endif