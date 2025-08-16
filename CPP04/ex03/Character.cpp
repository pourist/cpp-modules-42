#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(): Name("Unnamed")
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
#ifdef DEBUG
	std::cout << "Character constructor called" << std::endl; 
#endif
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
		this->inventory[i] = NULL;
	}		
#ifdef DEBUG
	std::cout << "Character destructor called" << std::endl; 
#endif
}

Character::Character(std::string _Name): Name(_Name)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
#ifdef DEBUG
	std::cout << "Character Parameterized constructor called" << std::endl;
#endif
}

Character::Character(const Character& src)
{
	this->Name = src.Name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = src.inventory[i] ? src.inventory[i]->clone() : NULL;
#ifdef DEBUG
	std::cout << "Character Copy constructor called" << std::endl;
#endif
}

Character	&Character::operator=(const Character & src)
{
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];
			this->inventory[i] = NULL;
		}
		for (int i = 0; i < 4; i++)
			this->inventory[i] = src.inventory[i] ? src.inventory[i]->clone() : NULL;
		this->Name = src.Name;
	}
#ifdef DEBUG
	std::cout << "Character Assignment operator called" << std::endl;
#endif
	return (*this);
}

std::string	const&	Character::getName() const
{
	return (this->Name);
}

void	Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "Invalid Materia\n";
		return;
	}
	if (m->in_use_check())
	{
		std::cout << "This Materia is in use.\n";
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			m->inuse(true);
			this->inventory[i] = m;
			return;
		}
	}
	std::cout << Name << " cannot equip more items; inventory is full.\n";
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || this->inventory[idx] == NULL)
		std::cout << "Invalid or empty slot.\n";
	else
	{
		inventory[idx]->inuse(false);
		this->inventory[idx] = NULL;
		std::cout << "Unequipped Materia from index " << idx << ".\n";
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || this->inventory[idx] == NULL)
		std::cout << "Invalid or empty slot.\n";
	else
	{
		this->inventory[idx]->use(target);
	}
}

void	Character::print_info()
{
	std::cout << "~~~~~~~~~\nCharacter: " << this->getName() << std::endl;
	std::cout << "Inventory:\n";
	for(int i = 0; i < 4; i++)
	{
		std::cout << "\t" << i << ". ";
		if (this->inventory[i] != NULL)
			std::cout << this->inventory[i]->getType() << std::endl;
		else
			std::cout << "empty" << std::endl;
	}
	std::cout << "~~~~~~~~~\n";	
}