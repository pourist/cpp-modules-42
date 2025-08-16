#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
#ifdef DEBUG
	std::cout << "Ice constructor called" << std::endl; 
#endif
}

Ice::~Ice()
{
#ifdef DEBUG
	std::cout << "Ice destructor called" << std::endl; 
#endif
}

Ice::Ice(const Ice& src): AMateria(src.type)
{
#ifdef DEBUG
	std::cout << "Ice Copy constructor called" << std::endl;
#endif
}

Ice	&Ice::operator=(const Ice & src)
{
    if (this != &src)
    {
        AMateria::operator=(src); // Delegate to the base class assignment operator
    }
#ifdef DEBUG
	std::cout << "Ice Assignment operator called" << std::endl;
#endif
	return (*this);
}

AMateria*   Ice::clone() const
{
    return (new Ice(*this));
}

void    Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
