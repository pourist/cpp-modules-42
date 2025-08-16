#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main ()
{
	ClapTrap C1("Carrot");
	ScavTrap S1 ("Spinat");
	//ScavTrap S2 (S1);
	S1.attack("Tomato");
	C1.attack("Potato");
	S1.takeDamage(12);
	C1.takeDamage(12);
	S1.takeDamage(12);
	C1.takeDamage(12);
	S1.attack("Tomato");
	C1.attack("Potato");
	C1.beRepaired(10);
	S1.beRepaired(10);
	S1.guardGate();
	S1.guardGate();
	S1.guardGate();
	S1.guardGate();
	S1.guardGate();
	std::cout << "\n\n";
	FragTrap	F1("Falafel");
	std::cout << "\n\n";
	F1.highFivesGuys();
	F1.attack("Egg");
}
