#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter
{
	private:
		std::string	Name;
		AMateria	*inventory[4];
	public:
		Character();
		~Character();
		Character(std::string Name);
		Character(const Character &src);

		Character &operator=(const Character &copy);

		std::string const& getName() const;
	 
 		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
		bool	inventory_check(AMateria* m);

		void	print_info();
};

#endif
