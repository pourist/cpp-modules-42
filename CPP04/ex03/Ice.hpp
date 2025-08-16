#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice();
		~Ice();
		Ice	&operator=(const Ice& src);
		Ice(const Ice& src);

		AMateria* clone() const;
		void use(ICharacter& target);
};
#endif