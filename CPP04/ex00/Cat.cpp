#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal("Cat")
{
#ifdef DEBUG    
        std::cout << "Cat default constructor called" << std::endl;
#endif
}

Cat::~Cat()
{
#ifdef DEBUG
	std::cout << "Cat destructor called" << std::endl;
#endif
}

Cat::Cat(const Cat &src): Animal(src)
{
#ifdef DEBUG
        std::cout << "Cat Copy constructor called" << std::endl;
#endif
}

Cat	&Cat::operator=(const Cat &src)
{
#ifdef DEBUG
        std::cout << "Cat copy assignment operator called" << std::endl;
#endif
        if (this != &src)
        {
                this->type = src.type;
        }
        return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}

std::string	Cat::getType() const
{
	return (type);
}
