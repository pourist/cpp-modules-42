#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "Animal.hpp"

class   Dog: public Animal{
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