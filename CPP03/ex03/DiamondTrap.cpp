#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
#ifdef	DEBUG
	std::cout << Yellow << "DiamondTrap default constructor called for "; 
	std::cout << getName() << Reset << std::endl;
#endif
	this->Name = "Unnamed";
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	this->guard_gate = false;
}

DiamondTrap::~DiamondTrap()
{
#ifdef	DEBUG
	std::cout << Yellow << "DiamonTrap destructor called for "; 
	std::cout << getName() << Reset << std::endl;
#endif
}

DiamondTrap::DiamondTrap(std::string Name): ClapTrap(Name + "_Clap_Trap")
{
#ifdef	DEBUG
	std::cout << Yellow << "DiamondTrap parametric constructor called for "; 
	std::cout << getName() << Reset << std::endl;
#endif
        this->Name = Name;
        this->hit_points = FragTrap::hit_points;
        this->energy_points = ScavTrap::energy_points;
        this->attack_damage = FragTrap::attack_damage;
        this->guard_gate = false;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src): ClapTrap(src), ScavTrap(src), FragTrap(src)
{
#ifdef	DEBUG
	std::cout << Yellow << "DiamonTrap copy constructor called for "; 
	std::cout << getName() << Reset << std::endl;
#endif
	*this = src;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &src)
{
	if (this != &src)
	{
		this->Name = src.Name;  
		this->hit_points = src.hit_points;
		this->energy_points = src.energy_points;
		this->attack_damage = src.attack_damage;
		this->guard_gate = src.guard_gate;
	}
#ifdef	DEBUG
	std::cout << Yellow << "DiamondTrap copy assignment operator called for " << Name << 
		 Reset <<std::endl;
#endif
	return (*this);
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Name: " << Blue << Name << Reset << std::endl;
	std::cout << "ClapTrap Name: " << Blue << ClapTrap::Name << Reset << std::endl;
}
