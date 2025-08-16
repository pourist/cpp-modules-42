#include "Dog.hpp"
#include <iostream>

Dog::Dog(): Animal("Dog")
{
#ifdef DEBUG
	std::cout << "Dog default constructor called" << std::endl;
#endif
}

Dog::~Dog()
{
#ifdef DEBUG
	std::cout << "Dog destructor called" << std::endl;
#endif
}

Dog::Dog(const Dog &src): Animal(src)
{
#ifdef DEBUG
	std::cout << "Dog Copy constructor called" << std::endl;
#endif
}

Dog	&Dog::operator=(const Dog& src)
{
#ifdef DEBUG
	std::cout << "Dog copy assignment operator called" << std::endl;
#endif
	if(this != &src)
	{
		this->type = src.type;
	}
	return (*this);
}

void	Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}

std::string	Dog::getType() const
{
	return (type);
}
