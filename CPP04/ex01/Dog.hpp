#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class   Dog: public Animal{
	private:
		    Brain* brain;
    public:
            Dog();
            virtual ~Dog();
            Dog(std::string type);
            Dog(const Dog& src);
            Dog  &operator=(const Dog &src);

            std::string	getType() const;
            void    makeSound() const;
};

#endif