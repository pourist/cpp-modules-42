#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	protected:
		bool	guard_gate;
	public:
		ScavTrap();
		ScavTrap(std::string _Name);
		~ScavTrap();
		ScavTrap	&operator=(ScavTrap const &src);
		ScavTrap(ScavTrap const &src);
		void	guardGate();
		void	attack(const std::string& target);
};

#endif
