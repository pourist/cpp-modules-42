#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Cure: public AMateria
{
	public:
 		Cure();
		~Cure();
		Cure	&operator=(const Cure& src);
		Cure(const Cure& src);

		AMateria* clone() const;
		void use(ICharacter& target);
};
#endif