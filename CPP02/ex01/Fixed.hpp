#define DEBUG

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
};

std::ostream&   operator<<(std::ostream& os, const Fixed& f);

#endif