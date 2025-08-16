#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap (): Name("Unnamed"), hit_points(10), energy_points(10), attack_damage(0){
#ifdef	DEBUG
	std::cout << "Default ClapTrap constructor called" << std::endl;
#endif
}

ClapTrap::~ClapTrap(){
#ifdef	DEBUG
	std::cout << "Destructor called for " << this->Name << std::endl;
#endif
}

ClapTrap::ClapTrap(const std::string &Name): Name(Name), hit_points(10), energy_points(10), attack_damage(0){
#ifdef	DEBUG
	std::cout << "Parametric constructor called for " << Name << std::endl;
#endif
}

ClapTrap::ClapTrap(ClapTrap const &src){
#ifdef	DEBUG
	std::cout << "Copy constructor called for " << src.getName() << std::endl;
#endif
	*this = src;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &src){
#ifdef	DEBUG
	std::cout << "Copy assignment operator called for " << Name << std::endl;
#endif
if	(this != &src)
	{
		this->Name = src.getName();
		this->hit_points = src.getHitPoints();
		this->energy_points = src.getEnergyPoints();
		this->attack_damage = src.getAttackDamage();
	}
	return (*this);
}

std::string	ClapTrap::getName() const
{
	return(this->Name);
}

unsigned int	ClapTrap::getHitPoints() const
{
	return (this->hit_points);
}

unsigned int	ClapTrap::getEnergyPoints() const
{
	return (this->energy_points);
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return (this->attack_damage);
}

void    ClapTrap::attack(const std::string& target)
{
	if (energy_points <= 0)
	{
		std::cout << "ClapTrap " << this->Name << " has no energy to attack!";
		std::cout << std::endl;
		return ;
	}
	if (hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->Name << " is too weak to attack "
			<< "with 0 hit points!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->Name << " attacks " << target << ", "
		<< "causing " << this->attack_damage << " points of damage!";
	this->energy_points--;
	std::cout << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points == 0)
	{
		std::cout << "ClapTrap " << this->Name 
			<< " has 0 hit points and can't take damage!" << std::endl;
		return;
	}
	if (amount > this->hit_points)
	{
		amount = hit_points;
		this->hit_points = 0;
	}
	else
		this->hit_points -= amount;
	std::cout << "ClapTrap " << Name << " takes " << amount << " damage , hit points now " 
		<< this->hit_points << "!" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_points <= 0)
	{
		std::cout << "ClapTrap " << this->Name << " has no energy to be repaired!";
		std::cout << std::endl;
		return ;
	}
	if (hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->Name << " is too weak to be repaired "
			"with 0 hit points!" << std::endl;
		return ;
	}
	this->energy_points--;
	this->hit_points += amount;
	std::cout << "ClapTrap " << this->Name << " repairs " << amount
		<< ", hit points now " << this->hit_points << std::endl;
}
