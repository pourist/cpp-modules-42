#ifndef POINT_H
# define POINT_H

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;
	public:
		Point();
		~Point();
		Point(Point const &other_point);
		Point(const float _x, const float _y);
		Point	&operator=(const Point &copy); //not allowed (const members)
		float	getX() const;
		float	getY() const;
};

std::ostream&	operator<<(std::ostream &os, const Point &p);

#endif
