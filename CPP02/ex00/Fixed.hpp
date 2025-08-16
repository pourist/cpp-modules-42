#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
    int                 value;
    static const int    fractional_bits = 8;

public:
    Fixed();
    Fixed(Fixed const& other_number);
    Fixed& operator=(Fixed const& copy);
    ~Fixed();

    int  getRawBits() const;
    void setRawBits(int const raw);
};

#endif