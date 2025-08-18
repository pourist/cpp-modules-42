#include "Span.hpp"

void    ft_test()
{
    try{
        std::cout << "-----42Test-----\n";
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void    test2(Span&  test, std::string str)
{
    std::cout << "\n-----" << str <<" Container Test-----\n";
    test.printSpan();
    std::cout <<  "* Longest  Span\n" ;
    try
    {
        std::cout << test.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout <<  "* Shortest Span\n"; 
    try
    {
        std::cout << "* Longest Span\n" << test.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "* Overload\n";
    try
    {
        test.addNumber(99);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main()
{
    ft_test();
    try
    {
        std::cout << "\n-----MyTest-----\n";
        Span    test(10); // size of 10
 
        for(int i = 1; i <= 10; i++)
            test.addNumber((i * i) + (i));
        test.printSpan();
        std::cout << "Shortest Span: " << test.shortestSpan() << std::endl;
        std::cout << "Longest  Span: " << test.longestSpan() << std::endl;
        test.addNumber(11); // adding 11th element throws error
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    Span    empty(0);
    Span    one_element(1);
    one_element.addNumber(42);

    test2(empty, "Empty");
    test2(one_element, "One Element");

    try
    {
        std::cout << "\n-----Large Number Test-----\n";
        Span    test(10000);
 
        for(int i = -5; i <= 9994; i++)
            test.addNumber(i * 3);
        //test.printSpan();
        std::cout << "Shortest Span: " << test.shortestSpan() << std::endl;
        std::cout << "Longest  Span: " << test.longestSpan() << std::endl;
        test.addNumber(11); // adding 11th element throws error
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}