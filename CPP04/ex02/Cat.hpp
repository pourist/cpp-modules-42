#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>
# include "Brain.hpp"

class	Cat : public Animal
{
	private:
		Brain*	brain;
	public:
		Cat();
		~Cat();
		Cat(const Cat &src);
		Cat	&operator=(const Cat& src);

		void	makeSound() const;
		std::string	getType() const;
};

#endif
