#pragma once
#include <stdexcept>
#include <iostream>

template<typename T>
class Array
{
private:
    T*      arr;
    unsigned int     len;
public:
    Array();
    Array(unsigned int n);
    ~Array();
    Array(const Array& src);

    Array   &operator=(const Array& src);
    const T       &operator[](unsigned int index) const;
    T       &operator[](unsigned int index);


    unsigned int     size() const;
};

template<typename T>
Array<T>::Array(): arr(NULL), len(0){}



template<typename T>
Array<T>::Array(unsigned int n): arr(new T[n]()), len(n){}


template<typename T>
Array<T>::~Array()
{
    delete [] this->arr;
}

template<typename T>
unsigned int    Array<T>::size() const
{
    return (len);
}

template<typename T>
Array<T>::Array(const Array& src): arr(new T[src.size()]), len(src.size())
{
    for(unsigned int i = 0; i < this->len; i++)
        this->arr[i] = src.arr[i];
}


template<typename T>
Array<T>   &Array<T>::operator=(const Array& src)
{
    if (this != &src)
    {
        delete [] this->arr;
        len = src.size();
        arr = new T[len];
        for (unsigned int i = 0; i < len; i++)
            this->arr[i] = src.arr[i];
    }
    return (*this);
}

template<typename T>
T       &Array<T>::operator[](unsigned int index)
{
    if (index >= this->len)
        throw (std::out_of_range("Index out of bounds"));
    return (arr[index]);
}

template<typename T>
const T       &Array<T>::operator[](unsigned int index) const
{
    if (index >= this->len)
        throw (std::out_of_range("Index out of bounds"));
    return (arr[index]);
}

template<typename T>
std::ostream&    operator<<(std::ostream& o, Array<T>const& array)
{
    if (array.size() == 0)
    {
        o << "Empty array.";
        return (o);
    }
    for (unsigned int i = 0; i < array.size(); i++)
    {
        if (sizeof(T) == sizeof(std::string))
            o << "\"" << array[i] << "\"";
        else if (sizeof(T) == sizeof(char))
            o << "\'" << array[i] << "\'";
        else
            o << array[i];
        if (i != array.size() - 1)
            o << ", " ;
    }
    return (o);
}

