#include "Brain.hpp"

Brain::Brain()
{
#ifdef DEBUG    
        std::cout << "Brain default constructor called" << std::endl;
#endif
}

Brain::~Brain()
{
#ifdef DEBUG    
        std::cout << "Brain destructor called" << std::endl;
#endif
}

Brain::Brain(const Brain& src)
{
#ifdef DEBUG    
        std::cout << "Brain Copy constructor called" << std::endl;
#endif
	for(int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
}

Brain	&Brain::operator=(const Brain &src)
{
#ifdef DEBUG    
        std::cout << "Brain copy assignment operator called" << std::endl;
#endif
	if (this != &src)
	{
		for(int i = 0; i < 100; i++)
			this->ideas[i] = src.ideas[i];
	}
	return (*this);
}
