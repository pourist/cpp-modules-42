#include "Animal.hpp"

Animal::Animal(): type("Unknown")
{
#ifdef DEBUG
	std::cout << "Animal default constructor called for " << type << std::endl;
#endif
}

Animal::~Animal()
{
#ifdef DEBUG
std::cout << "Animal destructor called for " << type << std::endl;
#endif
}

Animal::Animal(std::string _type): type(_type)
{
#ifdef DEBUG
        std::cout << "Animal Parametrical constructor called for " << type << std::endl;
#endif
}

Animal::Animal(const Animal &src)
{
	*this = src;
#ifdef DEBUG
        std::cout << "Animal Copy constructor called for " << type << std::endl;
#endif
}

Animal	&Animal::operator=(const Animal &src)
{
	if (this != &src)
	{
		this->type = src.type;
	}
#ifdef DEBUG
        std::cout << "Animal copy assignment operator called for " << type << std::endl;
#endif
	return (*this);
}

std::string	Animal::getType() const
{
	return(this->type);
}

void	Animal::makeSound() const
{
	std::cout << "This animal makes no specific sound." << std::endl;
}

