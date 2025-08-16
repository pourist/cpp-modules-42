#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class   HumanB
{
    private:
        std::string name;
        Weapon      *weapon;
    public:
        HumanB(const std::string& _name);
        ~HumanB();
        void    attack() const;
        void	setWeapon(Weapon &weapon);
};

#endif


