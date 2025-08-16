//#define DEBUG

#ifndef FIXED_HPP
# define FIXED_HPP


# include <iostream>
# include <string>
# include <cmath>

class	Fixed
{
	private:
		int	value;
		static const int	fractional_bits;
	public:
		Fixed();
		Fixed(const Fixed& other_number);
		Fixed(const int number);
		Fixed(const float number);
		~Fixed();
		float	toFloat( void ) const;
		int	toInt( void ) const;
		int	getRawBits() const;
		void	setRawBits(int const raw);
		static	Fixed&	min(Fixed& a, Fixed& b);
		static	Fixed&	max(Fixed& a, Fixed& b);
		static	const Fixed&	max(const Fixed& a, const Fixed& b);
		static	const Fixed&	min(const Fixed& a, const Fixed& b);
		Fixed	&operator=(const Fixed &copy);
		bool	operator==(const Fixed& fixed) const;
		bool	operator!=(const Fixed& fixed) const;
		bool	operator<=(const Fixed& fixed) const;
		bool	operator>=(const Fixed& fixed) const;
		bool	operator<(const Fixed& fixed) const;
		bool	operator>(const Fixed& fixed) const;
		float   operator/(Fixed fixed) const;
		float   operator*(Fixed fixed) const;
		float   operator+(Fixed fixed) const;
		float   operator-(Fixed fixed) const;
		Fixed	operator++(int);
		Fixed	&operator++();
		Fixed	&operator--();
		Fixed	operator--(int);
};


std::ostream&	operator<<(std::ostream& os, const Fixed& f);

#endif
