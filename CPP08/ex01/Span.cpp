
#include "Span.hpp"

Span::Span(unsigned int _N): N(_N)
{
}

Span::~Span()
{
}

Span::Span(const Span& src): N(src.N), container(src.container)
{
}

Span    &Span::operator=(const Span& src)
{
    if (this != &src)
    {
        this->container = src.container;
        this->N = src.N;
    }
    return (*this);
}

void    Span::addNumber(int num)
{
    if (this->container.size() < this->N)
        container.push_back(num);
    else
        throw (Span::fullSpan());
}

void    Span::addNumber(std::vector<int>::const_iterator begin, 
                        std::vector<int>::const_iterator end)
{
        if (this->container.size() + std::distance(begin, end) > this->N)
            throw (Span::fullSpan());
        this->container.insert(this->container.end(), begin, end);
}

int Span::shortestSpan() const
{
    if (this->container.size() < 2)
        throw(Span::noSpanFound());
    std::vector<int> temp = this->container;
    std::sort(temp.begin(), temp.end());
    int shortSpan = temp[1] - temp[0];
    for (unsigned int i = 0; i < temp.size() - 1; i++)
    {
        int diff = temp[i + 1] - temp[i];
        if (shortSpan > diff)
            shortSpan = diff;
    }
    return (shortSpan);
}

int Span::longestSpan() const
{
    if (this->container.size() < 2)
        throw(Span::noSpanFound());
    std::vector<int>::const_iterator    min = std::min_element(this->container.begin(), this->container.end());
    std::vector<int>::const_iterator    max = std::max_element(this->container.begin(), this->container.end());
    return (*max - *min);
}

const char *Span::fullSpan::what() const throw()
{
    return ("Error: The Span is full. Can't add new number.");
}

const char *Span::noSpanFound::what() const throw()
{
    return ("Error: No number or only one number found.");
}

void    Span::printSpan()
{
    std::vector<int>::iterator it = this->container.begin();
    std::cout << "[";
    while(it != this->container.end())
    {
        std::cout << *it;
        if (++it != this->container.end())
            std::cout << ", ";
    }
    std::cout << "]" << std::endl; 
}