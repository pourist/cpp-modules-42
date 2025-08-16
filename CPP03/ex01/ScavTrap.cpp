#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
#ifdef	DEBUG
	std::cout << Yellow << "ScavTrap default constructor called for "; 
	std::cout << getName() << Reset << std::endl;
#endif
	hit_points = 100;
    	energy_points = 50;
    	attack_damage = 20;
    	guard_gate = false;
}

ScavTrap::~ScavTrap()
{
#ifdef	DEBUG
	std::cout << Yellow << "ScavTrap destructor called for "; 
	std::cout << getName() << Reset << std::endl;
#endif
}

ScavTrap::ScavTrap(std::string Name): ClapTrap(Name)
{
#ifdef	DEBUG
	std::cout << Yellow << "ScavTrap parametric constructor called for "; 
	std::cout << getName() << Reset << std::endl;
#endif
	hit_points = 100;
    energy_points = 50;
	attack_damage = 20;
	guard_gate = false;
}

ScavTrap::ScavTrap(ScavTrap const &src): ClapTrap(src)
{
#ifdef	DEBUG
	std::cout << Yellow << "ScavTrap copy constructor called for "; 
	std::cout << getName() << Reset << std::endl;
#endif
	*this = src;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &src)
{
#ifdef	DEBUG
	std::cout << Yellow << "ScavTrap copy assignment operator called for " << Name << 
		 Reset <<std::endl;
#endif
	if (this != &src)
	{
		this->Name = src.getName();
		this->hit_points = src.getHitPoints();
		this->energy_points = src.getEnergyPoints();
		this->attack_damage = src.getAttackDamage();
		this->guard_gate = src.guard_gate;
	}
	return (*this);
}

void    ScavTrap::attack(const std::string& target)
{
	if (energy_points <= 0)
	{
		std::cout << "ScavTrap " <<  Blue << this->Name << Reset << " has no energy to attack";
		std::cout << std::endl;
		return ;
	}
	if (hit_points <= 0)
	{
		std::cout << "ScavTrap " << Blue << this->Name << " is too weak to attack "
			<< "with " << Green << "0" << Reset << " hit points" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << Blue << this->Name << Reset << " attacks " 
		<< Yellow << target << Reset
	       	<< ", causing " << Red << this->attack_damage << Reset << " points of damage";
	this->energy_points--;
	std::cout << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << Blue << Name << Reset << "'s guardgate mdoe is now ";
	if (!guard_gate)
	{
		std::cout << Green << "ON" << Reset << std::endl;
		guard_gate = true;
	}
	else
	{	
		std::cout << Red << "OFF" << Reset << std::endl;
		guard_gate = false;
	}
}