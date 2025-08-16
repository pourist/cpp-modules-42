#include "Array.hpp"
#include <iostream>

int main()
{
    std::cout << "\n**Testing Integer Array**\n";
    Array<int> A(4);

    std::cout << "Initial state of A: {" << A << "}" << std::endl;
    
    std::cout << "\n Modifying array values\n";
    try {
        A[0] = 10;
        A[1] = 20;
        A[2] = 30;
        A[3] = 40;
        std::cout << "Updated A: {" << A << "}" << std::endl;

        std::cout << "\nAttempting to modify A[4]\n";
        A[4] = 50;  // This should throw an exception
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n==============================\n";
    
    std::cout << "\n**Testing String Array**\n";
    
    // STRING
    
    Array<std::string> str(3);
    
    std::cout << "Initial state of str: {" << str << "}" << std::endl;
    
    std::cout << "\n Modifying string array values\n";
    try {
        str[0] = "Hello";
        str[1] = "42";
        str[2] = "!";
        std::cout << "Updated str: {" << str << "}" << std::endl;

        std::cout << "\nAttempting to modify str[3]\n";
        str[3] = "Out of Bounds";  // This should throw an exception
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "\n==============================\n";
    std::cout << "\n**Testing copy constructor**\n";
    Array<std::string> copy(str);
    std::cout << "\nCopy of str: " << copy << std::endl;
    str[1] = "World";

    std::cout << "\nComparing string and copy after modifying str[1]\n";
    std::cout << "\nString : " << str << std::endl;
    std::cout << "Copy   : " << copy << std::endl;
 
    std::cout << "\n==============================\n";
    std::cout << "\n**Testing assignment operator**\n";

    copy = str;
    std::cout << "\nComparing string and copy\n";
    std::cout << "\nString : " << str << std::endl;
    std::cout << "Copy   : " << copy << std::endl;

    copy[1] = "Evaluator";
    std::cout << "\nComparing string and copy after modifying str[1]\n";
    std::cout << "\nString : " << str << std::endl;
    std::cout << "Copy   : " << copy << std::endl;

}
