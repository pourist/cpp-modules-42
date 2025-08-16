#include "AMateria.hpp"

AMateria::AMateria(): in_use(false)
{
#ifdef DEBUG
	std::cout << "AMateria constructor called" << std::endl; 
#endif
}

AMateria::~AMateria()
{
#ifdef DEBUG
	std::cout << "AMateria destructor called" << std::endl; 
#endif
}

AMateria::AMateria(std::string const & _type): type(_type), in_use(false)
{
#ifdef DEBUG
	std::cout << "AMateria Parameterized constructor called" << std::endl;
#endif
}

AMateria::AMateria(const AMateria& src): in_use(0)
{
	(void)src;
#ifdef DEBUG
	std::cout << "AMateria Copy constructor called" << std::endl;
#endif
}

AMateria	&AMateria::operator=(const AMateria & src)
{
	(void)src;
#ifdef DEBUG
	std::cout << "AMateria Assignment operator called" << std::endl;
#endif
	return (*this);
}

std::string const	&AMateria::getType() const
{
	return (this->type);
}

void	AMateria::inuse(bool s)
{
	this->in_use = s;
}

bool	AMateria::in_use_check()
{
	return (in_use);
}

void    AMateria::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}