#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;


class AMateria
{
	protected:
		std::string	type;
		bool	in_use;
	public:
		AMateria();
		virtual ~AMateria();
		AMateria(std::string const & type);
		AMateria	&operator=(const AMateria& src);
		AMateria(const AMateria& src);

		std::string const	&getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		void	inuse(bool s);
		bool	in_use_check();
};

#endif
