#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
}

PmergeMe::PmergeMe(const PmergeMe& src){
    (void)src;
}

PmergeMe    &PmergeMe::operator=(const PmergeMe& src){
    (void)src;
    return(*this);
}

PmergeMe::PmergeMe(char* args[], int len){
    parse_args(args);
    std::cout << "Before:  ";
    display(this->list);
    double vector_duration = duration(&PmergeMe::mergeInsertSortVector, this->vec);
    double list_duration   = duration(&PmergeMe::mergeInsertSortList, this->list);
    std::cout << "After:   ";
    display(this->list);
    std::cout << "Time to process a range of " << len << " elements with std::vector :  " << std::fixed << std::setprecision(6)
    << vector_duration << " us" <<std::endl;
    std::cout << "Time to process a range of " << len <<" elements with std::list   :  " << std::fixed << std::setprecision(6)
    << list_duration << " us" << std::endl;
}

PmergeMe::~PmergeMe(){
}

void    PmergeMe::parse_args(char *args[])
{
    for(int i = 1; args[i]; i++)
    {
        int number = atoi(args[i]);
        if (number < 1)
            throw std::runtime_error("Error: invalid input");
        this->vec.push_back(number);
        this->list.push_back(number);
    }
}

void    PmergeMe::mergeInsertSortVector(std::vector<int>& _vector){
    int len = _vector.size();

    if (_vector.size() < 2)
        return;
    std::vector<int>::iterator begin = _vector.begin();
    std::vector<int>::iterator end = _vector.end();
    std::vector<int> a;
    std::vector<int> b;
    a.insert(a.end(), begin, begin + (len / 2));
    b.insert(b.end(), begin + (len / 2), end);
    mergeInsertSortVector(a);
    mergeInsertSortVector(b);
    _vector.clear();
    std::vector<int>::iterator it_a = a.begin();
    std::vector<int>::iterator it_b = b.begin();

    while (it_a != a.end() && it_b != b.end()) {
        if (*it_a < *it_b)
            _vector.push_back(*it_a++);
        else
            _vector.push_back(*it_b++);
    }

    while (it_a != a.end())
        _vector.push_back(*it_a++);
    while (it_b != b.end())
        _vector.push_back(*it_b++);
}


void PmergeMe::mergeInsertSortList(std::list<int>& _list) {
    int len = _list.size();
    if (len < 2)
        return;

    std::list<int>::iterator begin = _list.begin();
    std::list<int>::iterator mid = _list.begin();
    std::advance(mid, len / 2);
    std::list<int>::iterator end = _list.end();

    std::list<int> a(begin, mid);
    std::list<int> b(mid, end);

    mergeInsertSortList(a);
    mergeInsertSortList(b);

    _list.clear();
    std::list<int>::iterator it_a = a.begin();
    std::list<int>::iterator it_b = b.begin();

    while (it_a != a.end() && it_b != b.end()) {
        if (*it_a < *it_b)
            _list.push_back(*it_a++);
        else
            _list.push_back(*it_b++);
    }
    while (it_a != a.end())
        _list.push_back(*it_a++);
    while (it_b != b.end())
        _list.push_back(*it_b++);
}

template<typename T>
double    PmergeMe::duration(void(PmergeMe::*function)(T&), T& arg){
    timeval begin, end;

    gettimeofday(&begin, NULL);
    (this->*function)(arg);
    gettimeofday(&end, NULL);

    double duration = (end.tv_sec - begin.tv_sec)
                    + (end.tv_usec - begin.tv_usec) / 1e6;    return (duration);
}

template<typename T>
void    PmergeMe::display(T& container) const
{
    for (typename T::iterator it = container.begin(); it != container.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}


// ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
