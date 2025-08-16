#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->saved[i] = NULL;
#ifdef DEBUG
	std::cout << "MateriaSource constructor called" << std::endl; 
#endif
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->saved[i])
			delete this->saved[i];
        this->saved[i] = NULL;
	}		
#ifdef DEBUG
	std::cout << "MateriaSource destructor called" << std::endl; 
#endif
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	for (int i = 0; i < 4; i++)
		this->saved[i] = src.saved[i] ? src.saved[i]->clone() : NULL;
#ifdef DEBUG
	std::cout << "MateriaSource Copy constructor called" << std::endl;
#endif
}

MateriaSource	&MateriaSource::operator=(const MateriaSource & src)
{
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->saved[i])
				delete this->saved[i];
            this->saved[i] = NULL;
		}
		for (int i = 0; i < 4; i++)
			this->saved[i] = src.saved[i] ? src.saved[i]->clone() : NULL;
	}
#ifdef DEBUG
	std::cout << "MateriaSource Assignment operator called" << std::endl;
#endif
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *materia)
{
	int i = 0;
	while (this->saved[i] != NULL && i < 4)
		i++;
	if (i >= 4)
	{
		std::cout << "MateriaSource is full\n";
		return;
	}
	this->saved[i] = materia->clone();
	std::cout << materia->getType() << " saved in MateriaSource\n"; 
}

AMateria	*MateriaSource::createMateria(std::string const &to_copy)
{
	int i = 0;
	while (i < 4 && this->saved[i])
	{
		if ((this->saved)[i]->getType() == to_copy)
		{
			std::cout << "Created a copy of " << to_copy << "\n";
			return ((this->saved)[i]->clone());
		}
		i++;
	}
	std::cout << to_copy << " not found in MateriaSource\n";
	return (NULL);
}