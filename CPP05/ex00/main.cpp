#include "Bureaucrat.hpp"

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
}
