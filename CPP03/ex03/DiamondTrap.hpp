#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string	Name;
	public:
		DiamondTrap();
		~DiamondTrap();
		DiamondTrap(std::string Name);
		DiamondTrap(DiamondTrap const &src);
		DiamondTrap	&operator=(DiamondTrap const &src);
		
		void	attack(const std::string &target);
		void	whoAmI();
};

#endif