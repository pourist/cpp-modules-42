#include "Zombie.hpp"

int main()
{
    Zombie  ZombieA("ZombieA");
    Zombie  *ZombieB = newZombie("ZombieB");
    ZombieA.announce();
    (*ZombieB).announce();
    std::cout << std::endl;
    randomChump("ZombieC");
    std::cout << std::endl;
    delete ZombieB;
}