#include "iter.hpp"
#include "iostream"

int main()
{
    int array[] = {2, 3, 4, 5};
    std::cout << "Integers:\n";
    ::iter(array, 4, print_element);

    char str[] = "Hello";
    std::cout << "Characters:\n";
    ::iter(str, 5, print_element);

    double d[] = {4.5, 5.6, 6.7, 7.8, 8.9 , 10};
    std::cout << "Doubles:\n";
    ::iter(d, 6, print_element);

    std::string Cities[] = {"Berlin", "Tehran", "NY"};
    std::cout << "Strings:\n";
    ::iter(Cities, 3, print_element);
}