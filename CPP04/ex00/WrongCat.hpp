#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>
# include <string>

class	WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat &src);
		WrongCat	&operator=(const WrongCat& src);

		void	makeSound() const;
		std::string	getType() const;
};

#endif
