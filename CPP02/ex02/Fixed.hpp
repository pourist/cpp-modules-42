//#define DEBUG

#ifndef FIXED_HPP
#define FIXED_HPP
#include <string>
#include <ostream>

class Fixed {
private:
    int                 value;
    static const int    fractional_bits = 8;

public:
    Fixed();
    Fixed(Fixed const& other_number);
    Fixed& operator=(Fixed const& copy);
    ~Fixed();

    Fixed(const int& numb);
    Fixed(const float& numb);
    float toFloat( void ) const;
    int toInt( void ) const;
    
    int  getRawBits() const;
    void setRawBits(int const raw);

    bool	operator==(const Fixed& fixed) const;
    bool	operator!=(const Fixed& fixed) const;
    bool	operator<=(const Fixed& fixed) const;
    bool	operator>=(const Fixed& fixed) const;
    bool	operator<(const Fixed& fixed) const;
    bool	operator>(const Fixed& fixed) const;
    Fixed   operator+(Fixed const& rhs) const;
    Fixed   operator-(Fixed const& rhs) const;
    Fixed   operator*(Fixed const& rhs) const;
    Fixed   operator/(Fixed const& rhs) const;
    Fixed	operator++(int);
    Fixed	&operator++();
    Fixed	&operator--();
    Fixed	operator--(int);

    static	Fixed&	min(Fixed& a, Fixed& b);
    static	Fixed&	max(Fixed& a, Fixed& b);
    static	const Fixed&	max(const Fixed& a, const Fixed& b);
    static	const Fixed&	min(const Fixed& a, const Fixed& b);
};

std::ostream&   operator<<(std::ostream& os, const Fixed& f);

#endif