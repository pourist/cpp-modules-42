#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

template<typename T>
void    test_container(T& container, std::string type)
{
    std::cout << "\n-----" << type << "-----\n";
    for (int i = 1; i <= 100; i++) 
        container.push_back(i);
    try
    {
        std::cout << "Found: " << *easyfind(container, 93) << std::endl; // should find 3 
        std::cout << "Found: " << *easyfind(container, 123); // can't find 13 
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    container.push_back(70); // duplicate number check
    container.push_back(80);
    try
    {
        std::cout << "Found: " << *easyfind(container, 70) << std::endl; // duplicate number check 70
        typename T::iterator  it = easyfind(container, 70);
        it++;
        std::cout << "Next number: " << *it << std::endl; // to check if it points to first one if duplicate 
        std::cout << "Found: " << *easyfind(container, 80) << std::endl; // duplicate number check - last element
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    container.clear();
    try{
        std::cout << "Found: " << *easyfind(container, 3) << std::endl; // empty container
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    container.push_back(65); // with only one element
    try{
        std::cout << "Found: " << *easyfind(container, 65) << std::endl; 
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}


int main()
{
    std::vector<int>    vec;
    std::list<int>    lst;
    std::deque<int>    deq;

    test_container(vec, "VECTOR");
    test_container(lst, "LIST");
    test_container(deq, "DEQUE");
}