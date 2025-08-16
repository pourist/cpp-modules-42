#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): 
    AForm("PresidentialPardonForm", 25, 5), target("default")
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string _target): 
    AForm("PresidentialPardonForm", 25, 5), target(_target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src):
    AForm("PresidentialPardonForm", 25, 5), target(src.getTarget())
{
}

PresidentialPardonForm   &PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
    (void)src;
    return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
    return(this->target);
}

void PresidentialPardonForm::executeConcrete() const
{
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox.";
    std::cout << std::endl;
}