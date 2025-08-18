#include "MutantStack.hpp"
#include "list"

void    ft_test()
{
    std::cout << "\n-----List vs MutantStack-----\n";
    MutantStack<int> mstack;
    std::list<int>   lst;

    mstack.push(5);
    mstack.push(17);
    lst.push_back(5);
    lst.push_back(17);
    std::cout << "M: " << mstack.top() << std::endl;
    std::cout << "L: " << lst.back() << std::endl;
    mstack.pop();
    lst.pop_back();
    std::cout << "M size: " << mstack.size() << std::endl;
    std::cout << "L size: " << lst.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    std::list<int>::iterator it_list = lst.begin();
    std::list<int>::iterator ite_list = lst.end();
    ++it;
    --it;
    ++it_list;
    --it_list;
    std::cout << "M: ";
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << "\nL: ";
    while (it_list != ite_list)
    {
        std::cout << *it_list << " ";
        ++it_list;
    }
    std::cout << "\n";
    std::stack<int> s(mstack);
}


int    main()
{
    ft_test();
    std::cout << "\n-----Test-----\n";

    MutantStack<int> mts;
    for (int i = 0; i < 10; i++)
        mts.push(i);
    mts.print();
    std::cout << "\n--Erasing last element pop()--\n";
    mts.pop();
    mts.print();
    std::cout << "Begin: " << *mts.begin() << std::endl;
    std::cout << "End: " << *(mts.end() - 1) << std::endl;
    std::cout << "\n--Printing using iterator--\n";
    for(MutantStack<int>::iterator it = mts.begin(); it != mts.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "\n--Copy--\n";
    MutantStack<int> copy = mts;
    copy.print();

    if (!mts.empty())
        std::cout << "Mts is not empty first\n";
    while (mts.size())
        mts.pop();
    if (mts.empty())
        std::cout << "Mts is empty now\n";
}
