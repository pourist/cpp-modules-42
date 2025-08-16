#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria    *saved[4];
    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(const MateriaSource& src);
        MateriaSource   &operator=(const MateriaSource& src);

        void    learnMateria(AMateria *materia);
        AMateria*   createMateria(std::string const &to_copy);
};

#endif