#include "Classes.hpp"
#include <ctime>
#include <cstdlib> 
#include <iostream>

Base *generate(void)
{
    srand((unsigned)time(0));
    int i;
    i = (rand()%3);
    switch (i)
    {
        case (0):
            return (new A);
        case (1):
            return (new B);
        case (2):
            return (new C);
        default:
            return (NULL);
    }
}

void identify(Base* p)
{
    if (p == NULL)
        std::cout << "NULL" << std::endl;
    else if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try{
        A a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (...) {}
    try{
        B b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (...) {}
    try{
        C c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (...) {}
}

int main()
{
    Base *test = generate();
    std::cout << "Identified using pointer:\n";
    identify(test);
    std::cout << "Identified unsing refrence:\n";
    identify(&(*test));
    delete test;
}
