#include "Harl.hpp"
#include <iostream>

int main()
{
	Harl	h;

	h.complain("DEBUG");
	h.complain("INFO");
	h.complain("WARNING");
	h.complain("ERROR");
	std::cout << "\nINVALID:\n" ;
	h.complain("Something esle");
}
