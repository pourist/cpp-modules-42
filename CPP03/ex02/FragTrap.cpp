#include "FragTrap.hpp"

FragTrap::FragTrap()
{
#ifdef	DEBUG
	std::cout << Yellow << "FragTrap default constructor called for "; 
	std::cout << getName() << Reset << std::endl;
#endif
	hit_points = 100;
    energy_points = 100;
	attack_damage = 30;
}

FragTrap::~FragTrap()
{
#ifdef	DEBUG
	std::cout << Yellow << "FragTrap destructor called for "; 
	std::cout << getName() << Reset << std::endl;
#endif
}

FragTrap::FragTrap(std::string Name): ClapTrap(Name)
{
#ifdef	DEBUG
	std::cout << Yellow << "FragTrap parametric constructor called for "; 
	std::cout << getName() << Reset << std::endl;
#endif
	hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
}

FragTrap::FragTrap(FragTrap const &src): ClapTrap(src)
{
#ifdef	DEBUG
	std::cout << Yellow << "FragTrap copy constructor called for "; 
	std::cout << getName() << Reset << std::endl;
#endif
	*this = src;
}

FragTrap	&FragTrap::operator=(FragTrap const &src)
{
#ifdef	DEBUG
	std::cout << Yellow << "FragTrap copy assignment operator called for " << Name << 
		 Reset <<std::endl;
#endif
	if (this != &src)
	{
		this->Name = src.getName();
		this->hit_points = src.getHitPoints();
		this->energy_points = src.getEnergyPoints();
		this->attack_damage = src.getAttackDamage();
	}
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	std::cout << Blue << Name << Reset << ": High fives!" << std::endl;
}
