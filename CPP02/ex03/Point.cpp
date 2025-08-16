#include "Point.hpp"

Point::Point(): x() , y()
{
#ifdef DEBUG
	std::cout << "Default Point constructor called" << std::endl;
#endif
}

Point::~Point()
{
#ifdef DEBUG
	std::cout << "Default Point destructor called" << std::endl;
#endif
}

Point::Point(Point const &other_point): x(other_point.x), y(other_point.y)
{
#ifdef DEBUG
	std::cout << "Copy Point constructor called" << std::endl;
#endif
}

Point::Point(const float _x, const float _y): x(Fixed(_x)), y(Fixed(_y))
{
#ifdef DEBUG
	std::cout << "Parameterized Point constructor called" << std::endl;
#endif
}

Point	&Point::operator=(const Point& copy)
{
#ifdef DEBUG
	std::cout << "Assignation operator not allowed for this class" << std::endl;
	// x and y are const members and can not be reassigned
#endif
	if (this != &copy)
		return (*this);
	return (*this);
}

float	Point::getX() const
{
	return (x.toFloat());
}	

float	Point::getY() const
{
	return (y.toFloat());
}	

std::ostream	&operator<<(std::ostream& os, Point const &p)
{
	os << "(" << p.getX() << "," << p.getY() << ")";
	return (os);
}
