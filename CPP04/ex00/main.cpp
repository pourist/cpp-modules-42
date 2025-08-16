#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	/*Animal	A("Anoosh");
	Cat 	cat;
	Dog	dog;

	std::cout << A.getType() << " Said: ";
	A.makeSound();
	std::cout << cat.getType() << " Said: ";
	cat.makeSound();
	std::cout << dog.getType() << " Said: ";
	dog.makeSound();

	Cat	cat2(cat);
	std::cout << cat2.getType() << " Said: ";
	cat2.makeSound();

	Dog	dog2 = dog;
	std::cout << dog2.getType() << " Said: ";
	dog2.makeSound();
	
	Animal	animal2;
	std::cout << animal2.getType() << " Said: ";
	animal2.makeSound();*/

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const	WrongAnimal* wrongmeta = new WrongAnimal();
	const	WrongAnimal* wrongi = new WrongCat();
	wrongi->makeSound();
	wrongmeta->makeSound();
}
