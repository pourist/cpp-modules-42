#pragma once

#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <vector>
#include <list>
#include <stdlib.h>
#include <iomanip>


class PmergeMe
{
    private:
        std::vector<int>    vec;
        std::list<int>      list;

        PmergeMe();
        PmergeMe(const PmergeMe& src);
        PmergeMe    &operator=(const PmergeMe& src);

    public:
        PmergeMe(char* args[], int len);
        ~PmergeMe();

        void    parse_args(char *args[]);
        void    mergeInsertSortList(std::list<int>& _list);
        void    mergeInsertSortVector(std::vector<int>& _vector);

        template<typename T>
        double    duration(void(PmergeMe::*function)(T&), T& arg);

        template<typename T>
        void    display(T& container) const;
};