#include "Harl.hpp"
#include <iostream>
#include <string>

void control(const std::string& level) {
    Harl h;

    static const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while (i < 4) {
        if (level == levels[i])
            break;
        i++;
    }

    switch (i) {
        case 0:
            h.complain(levels[0]);
            /* fall through */
        case 1:
            h.complain(levels[1]);
            /* fall through */
        case 2:
            h.complain(levels[2]);
            /* fall through */
        case 3:
            h.complain(levels[3]);
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "[ Probably complaining about insignificant problems ]\n";
        return 1;
    }
    control(argv[1]);
    return 0;
}