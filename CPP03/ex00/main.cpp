#include "ClapTrap.hpp"

int main ()
{
	ClapTrap Anoosh("Anoosh");
	ClapTrap Mamad("Mamad Panguan");


	Anoosh.attack(Mamad.getName());
	Mamad.takeDamage(1);
	Anoosh.attack(Mamad.getName());
	Mamad.takeDamage(1);
	Mamad.attack(Mamad.getName());
	Anoosh.takeDamage(1);
	Anoosh.attack(Mamad.getName());
	Mamad.takeDamage(1);
	Anoosh.beRepaired(3);
}
