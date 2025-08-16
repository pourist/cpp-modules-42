#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main()
{
    AForm *A[3] = {NULL, NULL, NULL}; 
    try
    {
        A[0] = new ShrubberyCreationForm("Home");
        A[1] = new PresidentialPardonForm("Mehmet");
        A[2] = new RobotomyRequestForm("Anoosh");

        for (int i = 0; i < 3; i++)
            std::cout << *A[i] << std::endl;
        Bureaucrat  B("Mr.B", 50);
        std::cout << "------------\n";
        for (int i = 0; i < 3; i++)
        {
            B.signForm(*A[i]);
            std::cout << std::endl;
            B.executeForm(*A[i]);
            std::cout << "------------\n";
        }
        for (int i = 0; i < 3; i++)
            std::cout << *A[i] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    for (int i = 0; i < 3; i++)
    {
        if (A[i] != NULL)
            delete A[i];
    }
}
