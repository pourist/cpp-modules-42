#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    try
    {
        if (argc < 2)
            throw(openFileError());
        Btc btc(argv[1]);
    }
    catch (const std::exception& e)
    {
            std::cout << e.what() << std::endl;
    }
}