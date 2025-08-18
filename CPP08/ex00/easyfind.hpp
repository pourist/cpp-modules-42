#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

class   notFound : public std::exception
{
    public:
        const char  *what() const throw()
        {
            return ("Error: Number not found.");
        }
};


template<typename T>
typename T::iterator    easyfind(T& container, int value)
{
    typename T::iterator    it = std::find(container.begin(), container.end(), value);

    if (it != container.end())
        return(it);
    else
        throw  (notFound());
}

#endif





