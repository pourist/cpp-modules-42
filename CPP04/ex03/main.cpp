#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main()
{
	AMateria *C = new Cure();
	Character *Anoosh = new Character("Anoosh");
	Anoosh->equip(C);
	Anoosh->print_info();
	Anoosh->equip(C);
	Anoosh->print_info();

	Anoosh->unequip(2);
	Anoosh->unequip(0);
	Anoosh->unequip(4);
	Anoosh->print_info();

	AMateria *A = new Ice();
	AMateria *B = new Cure();
	AMateria *D = new Ice();
	AMateria *E = new Cure();

	Anoosh->equip(A);
	Anoosh->equip(B);
	Anoosh->equip(C);
	Anoosh->equip(D);
	Anoosh->print_info();

	Anoosh->equip(E);
	Anoosh->print_info();

	Anoosh->unequip(2);
	Anoosh->print_info();

	Anoosh->equip(A);
	Anoosh->equip(B);
	Anoosh->equip(C);
	Anoosh->equip(D);
	Anoosh->print_info();

	Character *Mamad = new Character("Mamad");
	Mamad->equip(C);
	Mamad->equip(E);
	Mamad->print_info();

	Mamad->use(1, *Anoosh);
	Mamad->use(0, *Anoosh);

	Mamad->unequip(0);

	MateriaSource source;

	source.learnMateria(A);
	AMateria *last =	source.createMateria("ice");
	AMateria *empty =	source.createMateria("cube");

	delete last;
	delete E;
	delete Anoosh;
	delete Mamad;
	(void)empty;
}
