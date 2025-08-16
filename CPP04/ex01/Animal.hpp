//#define DEBUG

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class   Animal{
    protected:
            std::string type;
    public:
            Animal();
            virtual ~Animal();
            Animal(std::string type);
            Animal(const Animal& src);
            Animal  &operator=(const Animal &src);

            std::string	getType() const;
            virtual void    makeSound() const;
};

#endif