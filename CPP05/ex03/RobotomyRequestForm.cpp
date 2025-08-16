#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(): 
    AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string _target): 
    AForm("RobotomyRequestForm", 72, 45), target(_target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src):
    AForm("RobotomyRequestForm", 72, 45), target(src.getTarget())
{
}

RobotomyRequestForm   &RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
    (void)src;
    return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
    return(this->target);
}

void RobotomyRequestForm::executeConcrete() const
{
    std::cout << "* Drilling noises *\n";
    if ((rand() % 2) == 1)
    {
        std::cout << this->getTarget();
        std::cout << " has been robotomized successfully\n";
    }
    else
        std::cout << "Robotomy of " << this->getTarget() << " failed.\n";
}