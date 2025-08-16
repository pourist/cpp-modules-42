#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int	main()
{
	std::cout << "Test 1 -- as in subject\n";
	Animal*	A[10];

	for (int i = 0; i < 5; i++)
		A[i] = new Cat;
	for (int i = 5; i < 10; i++)
		A[i] = new Dog;
	for (int i = 0; i < 10; i++)
		(*A[i]).makeSound();
	for (int i = 0; i < 10; i++)
		delete A[i];

	std::cout << "\n\n\nTest 2 -- Deep copy check.\n";
	Cat	*c1 = new Cat;
	Cat	c2;
       	c2 = *c1;

	delete c1;
	c2.makeSound();

	std::cout << "\n" << std::endl;
	Cat *catA = new Cat;
	Cat *catB = new Cat;

	*catA = *catB;
	(*catA).makeSound();
	(*catB).makeSound();
	delete catA;
	delete catB;

	std::cout << "\n" << std::endl;

	Cat *cat1 = new Cat;
	Cat *cat2 = new Cat(*cat1);

	
	(*cat1).makeSound();
	(*cat2).makeSound();
	delete cat1;
	delete cat2;

}
