#include "Fixed.hpp"
#include <iostream>
# include <cmath>

const int Fixed::fractional_bits;

Fixed::Fixed() : value(0) {
    #ifdef DEBUG
        std::cout << "Default constructor called\n";
    #endif
}

Fixed::Fixed(Fixed const& other_number)
{
    #ifdef DEBUG
    std::cout << "Copy constructor called\n";
    #endif
    this->value = other_number.getRawBits();
}

Fixed& Fixed::operator=(Fixed const& copy) {
    #ifdef DEBUG
    std::cout << "Copy assignment operator called\n";
    #endif
    if (this != &copy) {
        this->value = copy.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    #ifdef DEBUG
    std::cout << "Destructor called\n";
    #endif
}

Fixed::Fixed(const int& numb): value(numb << fractional_bits){
#ifdef DEBUG
	std::cout << "Int Constructor called\n";
#endif
}

Fixed::Fixed(float const& numb)
: value(static_cast<int>(roundf(numb * (1 << fractional_bits))))
{
#ifdef DEBUG
    std::cout << "Float constructor called\n";
#endif
}

float Fixed::toFloat( void ) const{
    return static_cast<float>(this->value) / (1 << fractional_bits);
}

int Fixed::toInt( void ) const{
    return(this->value >> fractional_bits);
}

int Fixed::getRawBits() const {
#ifdef DEBUG
    std::cout << "getRawBits member function called\n";
#endif
    return this->value;
}

void Fixed::setRawBits(int const raw) {
    this->value = raw;
}

std::ostream&   operator<<(std::ostream& os, const Fixed& f){
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

Fixed Fixed::operator+(Fixed const& rhs) const {
    Fixed out;
    out.setRawBits(this->value + rhs.value);
    return out;
}

Fixed Fixed::operator-(Fixed const& rhs) const {
    Fixed out;
    out.setRawBits(this->value - rhs.value);
    return out;
}

Fixed Fixed::operator*(Fixed const& rhs) const {
    Fixed out;
    long tmp = static_cast<long>(this->value) * rhs.value;
    out.setRawBits(static_cast<int>(tmp >> fractional_bits));
    return out;
}

Fixed Fixed::operator/(Fixed const& rhs) const {
    Fixed out;
    long tmp = (static_cast<long>(this->value) << fractional_bits) / rhs.value;
    out.setRawBits(static_cast<int>(tmp));
    return out;
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