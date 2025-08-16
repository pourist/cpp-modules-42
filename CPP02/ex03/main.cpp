#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point);

int	main()
{
	Point	a(4, 6);
	Point	b(0, 3);
	Point	c(-2, 4);
	Point	point(0, 3);

	if(bsp(a, b, c, point))
		std::cout << "In\n";
	else
		std::cout << "Out\n";
	return 0;
}
