#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& _name): name(_name), weapon(NULL){
}

HumanB::~HumanB(){}

void    HumanB::attack() const {
    if (this->weapon)
    {
        std::cout << name << " attacks with their " << weapon->getType();
        std::cout << std::endl;
        return;
    }
    std::cout << name << " has no weapon to attack with!" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon){
    this->weapon = &weapon;
}