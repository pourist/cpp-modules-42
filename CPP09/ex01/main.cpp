#include "RPN.hpp"

int main(int argv, char* argc[])
{
    if (argv != 2)
    {
        std::cout << "Usage: ./RPN \"<expression>\"" << std::endl;
        return (1);
    }
    try
    {
        RPN rpb(argc[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}