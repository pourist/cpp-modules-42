#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
#ifdef DEBUG    
        std::cout << "WrongCat default constructor called" << std::endl;
#endif
}

WrongCat::~WrongCat()
{
#ifdef DEBUG
	std::cout << "WrongCat destructor called" << std::endl;
#endif
}

WrongCat::WrongCat(const WrongCat &src): WrongAnimal(src)
{
#ifdef DEBUG
        std::cout << "WrongCat Copy constructor called" << std::endl;
#endif
}

WrongCat	&WrongCat::operator=(const WrongCat &src)
{
#ifdef DEBUG
        std::cout << "WrongCat copy assignment operator called" << std::endl;
#endif
        if (this != &src)
        {
                this->type = src.type;
        }
        return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Very Wrong Meow! Meow!" << std::endl;
}

std::string	WrongCat::getType() const
{
	return (type);
}
