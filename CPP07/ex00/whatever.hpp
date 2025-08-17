#ifndef WHATEVER_CPP
#define  WHATEVER_CPP

template <typename T>
void    swap(T& A, T& B)
{
    T   temp;

    temp = A;
    A = B;
    B = temp;
}

template <typename T>
T   min(T& a, T& b)
{
    if (a < b)
        return a;
    return b;
}

template <typename T>
T   max(T& a, T& b)
{
    if (a > b)
        return a;
    return b;
}

#endif
