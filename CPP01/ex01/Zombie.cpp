#include "Zombie.hpp"

void	Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::set_name(std::string _name)
{
	name = _name;
}

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << name << " died.\n";
}