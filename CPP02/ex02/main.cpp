#include "Fixed.hpp"
#include <iostream>

int	main()
{
	Fixed		a (2);
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c (b);
	std::cout << a << " * " << b << " = " << a * b << std::endl;
	std::cout << a << " / " << b << " = " << a / b << std::endl;
	std::cout << a << " + " << b << " = " << a + b << std::endl;
	std::cout << a << " - " << b << " = " << a - b << std::endl;
	if (a < b)
		std::cout << "True\n";
	if (!(a > b))
		std::cout << "True\n";
	if (a != b)
		std::cout << "True\n";
	if (b == c)
		std::cout << "True\n";
	if (b <= c)
		std::cout << "True\n";
	if (b >= c)
		std::cout << "True\n";
	float a_value = (2 * (1 << 8));
	std::cout << a << " = " << (a_value / (1 << 8)) << std::endl;
	std::cout << ++a << " = " << (++a_value / (1 << 8)) << std::endl;
	std::cout << a << " = " << ((a_value / (1 << 8))) << std::endl;
	std::cout << a++ << " = " << (a_value++ / (1 << 8)) << std::endl;
	std::cout << a << " = " << (a_value / (1 << 8)) << std::endl;

	std::cout << b << std::endl;

	std::cout << "Max: " << Fixed::max( a, b ) << std::endl;
	std::cout << "Min: " << Fixed::min( a, b ) << std::endl;

	return 0;
}
