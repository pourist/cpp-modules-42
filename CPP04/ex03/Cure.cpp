#include "Cure.hpp"

Cure::Cure(): AMateria("Cure")
{
#ifdef DEBUG
	std::cout << "Cure constructor called" << std::endl; 
#endif
}

Cure::~Cure()
{
#ifdef DEBUG
	std::cout << "Cure destructor called" << std::endl; 
#endif
}

Cure::Cure(const Cure& src): AMateria(src.type)
{
#ifdef DEBUG
	std::cout << "Cure Copy constructor called" << std::endl;
#endif
}

Cure	&Cure::operator=(const Cure & src)
{
    if (this != &src)
    {
        AMateria::operator=(src); // Delegate to the base class assignment operator
    }
#ifdef DEBUG
	std::cout << "Cure Assignment operator called" << std::endl;
#endif
	return (*this);
}

AMateria*   Cure::clone() const
{
    return (new Cure(*this));
}

void    Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
