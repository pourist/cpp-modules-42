#include "PmergeMe.hpp"

int main(int argv, char* argc[])
{
    if (argv < 2)
    {
        std::cerr << "Error: at least one positive integer is required as input." << std::endl;
        return (1);
    }
    try{
        PmergeMe pmergeme(argc, argv - 1);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}