#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(const std::string _target);
        PresidentialPardonForm(const PresidentialPardonForm& src);
        PresidentialPardonForm   &operator=(const PresidentialPardonForm& src);

        std::string getTarget() const;

        void    executeConcrete() const;
};

#endif