#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("Unknown")
{
#ifdef DEBUG
	std::cout << "WrongAnimal default constructor called for " << type << std::endl;
#endif
}

WrongAnimal::~WrongAnimal()
{
#ifdef DEBUG
std::cout << "WrongAnimal destructor called for " << type << std::endl;
#endif
}

WrongAnimal::WrongAnimal(std::string _type): type(_type)
{
#ifdef DEBUG
        std::cout << "WrongAnimal Parametrical constructor called for " << type << std::endl;
#endif
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
#ifdef DEBUG
        std::cout << "WrongAnimal Copy constructor called for " << type << std::endl;
#endif
	*this = src;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &src)
{
#ifdef DEBUG
        std::cout << "WrongAnimal copy assignment operator called for " << type << std::endl;
#endif
	if (this != &src)
	{
		this->type = src.type;
	}
	return (*this);
}

std::string	WrongAnimal::getType() const
{
	return(this->type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "This WrongAnimal makes no specific sound." << std::endl;
}

