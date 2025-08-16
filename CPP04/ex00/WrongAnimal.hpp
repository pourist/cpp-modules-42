#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "iostream"
# include "string"

class	WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &src);
		WrongAnimal	&operator=(WrongAnimal const &src);

		std::string	getType() const;
		virtual void	makeSound() const;
};

#endif
