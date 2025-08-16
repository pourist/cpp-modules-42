#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
    // too high too low constructor check
    try{
        Bureaucrat  High("Ali", -1);
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try{
        Bureaucrat  Low("Ali", 151);
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << std::endl;

    // Bureaucrat inc and dec test
    try{
    Bureaucrat A("Pingu",10);
    std::cout << A;
    A.increment();
    std::cout << A;
    A.increment(5);
    std::cout << A;
    A.increment(20);
    std::cout << A;
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try{
        Bureaucrat B("Pinga", 150);
        std::cout << B;
        B.decrement();
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Form constructors test
    try{
        Form    Fajr("Fajr", 100, 100);
        std::cout << "\n\n" << Fajr << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try{
        Form    Zajr("Zajr", -30, 30);
        std::cout << "\n\n" << Zajr << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "\n*---------------------------*\n";

    // Sign form test
    try{
        Bureaucrat John("John", 60);
        Form    form_A("Form A", 10, 30);
        std::cout << "\n\n" << form_A << std::endl;
        John.signForm(form_A);
        std::cout << "\n\n" << form_A << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "\n*---------------------------*\n";
    try{
        Bureaucrat Good("Dudi", 8);
        Form    form("Form B", 10, 30);
        std::cout << "\n\n" << form << std::endl;
        Good.signForm(form);
        std::cout << "\n\n" << form << std::endl;
        Good.signForm(form);
        std::cout << "\n\n" << form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}
