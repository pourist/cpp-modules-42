#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
		FragTrap();
		~FragTrap();
		FragTrap(std:: string Name);
		FragTrap(FragTrap const &src);
		FragTrap	&operator=(FragTrap const &src);
		
		void	highFivesGuys();
};


#endif
