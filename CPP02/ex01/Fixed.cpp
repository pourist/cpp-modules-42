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
    std::cout << "Copy constructor called\n";
    this->value = other_number.getRawBits();
}

Fixed& Fixed::operator=(Fixed const& copy) {
    std::cout << "Copy assignment operator called\n";
    if (this != &copy) {
        this->value = copy.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
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
    std::cout << "getRawBits member function called\n";
    return this->value;
}

void Fixed::setRawBits(int const raw) {
    this->value = raw;
}

std::ostream&   operator<<(std::ostream& os, const Fixed& f){
    os << f.toFloat();
    return (os);
}