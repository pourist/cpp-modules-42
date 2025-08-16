#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug()
{
	std::cout << "[ DEBUG ]\n" ;
	std::cout << "I love having extra bacon for my.\n"<< std::endl;
}

void	Harl::info()
{
	std::cout << "[ INFO ]\n" ;
	std::cout << 	"I cannot believe adding extra bacon costs more money.\n" << std::endl;
}

void	Harl::warning()
{
	std::cout << "[ Warning ]\n" ;
	std::cout << "I think I deserve to have some extra bacon for free.\n" << std::endl;
}

void	Harl::error()
{
	std::cout << "[ ERROR ]\n" ;
	std::cout << 	"This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

typedef void (Harl::*Handler)();

void Harl::complain(const std::string& level) {
    static const std::string levels[4]  = { "DEBUG", "INFO", "WARNING", "ERROR" };
    static const Handler     actions[4] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

    for (int i = 0; i < 4; ++i) {
        if (level == levels[i]) {
            (this->*actions[i])();
            return;
        }
    }
    std::cout << "Invalid level\n";
}