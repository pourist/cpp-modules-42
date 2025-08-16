#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main()
{
    AForm*   rff = NULL;

    try
    {
        Intern  trump;
        Bureaucrat Bean("Mr.Bean", 72);

        rff = trump.makeForm("robotomy request", "Bender");
        std::cout << *rff << std::endl;
        Bean.signForm(*rff);
        std::cout << std::endl << *rff;
        AForm*  wrong;
        wrong = trump.makeForm("random", "me");
        (void)wrong;
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    if (rff != NULL)
        delete (rff);
}
