#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void    print_element(T &element)
{
    std::cout << element << std::endl;
}

template<typename T>
void    iter(T  *array, size_t len, void (*function)(T &element))
{
    for(size_t i = 0; i < len; i++)
        function(array[i]);
}

#endif
