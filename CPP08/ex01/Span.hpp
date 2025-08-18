#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Span
{
    private:
        unsigned int  N;
        std::vector<int>    container;

        Span();

    public:
        Span(unsigned int _N);
        ~Span();
        Span(const Span& src);
        Span    &operator=(const Span& src);

        void    addNumber(int num);
        void    addNumber(std::vector<int>::const_iterator begin, 
                          std::vector<int>::const_iterator end);
        int     shortestSpan() const;
        int     longestSpan() const;

        class   fullSpan : public std::exception
        {
            const char *what() const throw();
        }; 
        class   noSpanFound : public std::exception
        {
            const char *what() const throw();
        };

        void    printSpan();
};

#endif