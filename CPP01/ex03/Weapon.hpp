#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class   Weapon
{
    private:
        std::string type;
    public:
        Weapon(const std::string& _type);
        ~Weapon();

        const   std::string& getType() const;
        void    setType(const std::string& type);
};

#endif