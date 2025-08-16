#define DEBUG

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include "ClapTrap.h"
#include <string>


class ClapTrap{
	protected:
		std::string	Name;
		unsigned int	hit_points;
		unsigned int	energy_points;
		unsigned int	attack_damage;
    public:
        ClapTrap();
		~ClapTrap();
        ClapTrap(const std::string& _Name);
        ClapTrap(const ClapTrap &src);
        ClapTrap    &operator=(const ClapTrap &src);

        std::string	getName() const;
		unsigned int	getHitPoints() const;
		unsigned int	getEnergyPoints() const;
		unsigned int	getAttackDamage() const;


		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif