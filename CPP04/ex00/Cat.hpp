#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "Animal.hpp"


class   Cat: public Animal{
    public:
            Cat();
            virtual ~Cat();
            Cat(std::string type);
            Cat(const Cat& src);
            Cat  &operator=(const Cat &src);

            std::string	getType() const;
            void    makeSound() const;
};

#endif