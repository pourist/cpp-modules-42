#include "Fixed.hpp"

const int	Fixed::fractional_bits = 8;

// constructor

Fixed::Fixed() : value(0)
{
#ifdef DEBUG
	std::cout << "Default constructor called\n";
#endif
}

// int constructor

Fixed::Fixed(const int number)
{
#ifdef DEBUG
	std::cout << "Int Constructor called\n";
#endif
	value = number << fractional_bits;
}

// float constructor

Fixed::Fixed(const float number)
{
#ifdef DEBUG
	std::cout << "Float Constructor called\n";
#endif
	value = roundf (number * ( 1 << fractional_bits));
}

// copy constructor

Fixed::Fixed(Fixed const &other_number)
{
#ifdef DEBUG
	std::cout << "Copy Constructor called\n";
#endif
	*this = other_number;
}

// destructor

Fixed::~Fixed()
{
#ifdef DEBUG
	std::cout << "Destructor called\n";
#endif
}

// Member Functions

int	Fixed::toInt( void ) const
{
	return (value >> fractional_bits);
}

float	Fixed::toFloat( void ) const
{
	return ((float)value / (1 << fractional_bits));
}

int	Fixed::getRawBits(void) const
{
	return (this->value);
}


void	Fixed::setRawBits( int const raw )
{
	this->value = raw;
}


// Operator Overloads

Fixed	&Fixed::operator=(const Fixed &copy)
{
#ifdef DEBUG
	std::cout << "Assignation operator called\n";
#endif
	this->value = copy.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return (os);
}

// comparison operator overloads

bool	Fixed::operator==(const Fixed& fixed) const
{
	return (this->value == fixed.value);
}

bool	Fixed::operator!=(const Fixed& fixed) const
{
	return (this->value != fixed.value);
}

bool	Fixed::operator<=(const Fixed& fixed) const
{
	return (this->value <= fixed.value);
}

bool	Fixed::operator>=(const Fixed& fixed) const
{
	return (this->value >= fixed.value);
}


bool	Fixed::operator<(const Fixed& fixed) const
{
	return (this->value < fixed.value);
}

bool	Fixed::operator>(const Fixed& fixed) const
{
	return (this->value > fixed.value);
}

// Arithmetic operator overload

float	Fixed::operator+(Fixed fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

float   Fixed::operator-(Fixed fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

float   Fixed::operator*(Fixed fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

float   Fixed::operator/(Fixed fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}

// PRE increment decrement operators

Fixed	&Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

// POST increment decrement operators

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	(this->value)++;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	(this->value)--;
	return (temp);
}

// Min and Max

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a <= b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a >= b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a <= b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a >= b)
		return (a);
	return (b);
}
