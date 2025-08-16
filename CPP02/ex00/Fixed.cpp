#include "Fixed.hpp"
#include <iostream>

const int Fixed::fractional_bits;

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called\n";
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

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called\n";
    return this->value;
}

void Fixed::setRawBits(int const raw) {
    this->value = raw;
}
