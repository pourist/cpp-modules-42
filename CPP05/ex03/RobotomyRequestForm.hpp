#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{    
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(const std::string _target);
        RobotomyRequestForm(const RobotomyRequestForm& src);
        RobotomyRequestForm   &operator=(const RobotomyRequestForm& src);

        std::string getTarget() const;

        void    executeConcrete() const;
};

#endif