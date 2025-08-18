#pragma once

#include <iostream>
#include <exception>
#include <map>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <limits.h>
#include <stdexcept>

class Btc
{
    private:
        std::ifstream    database;
        std::ifstream    inFile;
        std::map<int, float>    priceMap;

        Btc();
        Btc(const Btc& src);
        Btc &operator=(const Btc& src);
    public:
        Btc(char *file);
        ~Btc();

        void    parseDatabase();
        float   stofCheck(std::string number, std::string type);
        int     strToDate(std::string date, std::string line);
        void    print_result();
};

class openFileError: public std::exception
{
    const char* what() const throw()
    {
        return ("could not open file.");
    }
};

class openDatabaseError: public std::exception
{
    const char* what() const throw()
    {
        return ("could not open database.");
    }
};

class databaseFormatError: public std::exception
{
    const char* what() const throw()
    {
        return ("database format error.");
    }
};

class inFileFormatError: public std::exception
{
    const char* what() const throw()
    {
        return ("infile format error.");
    }
};

class badInput: public std::exception
{
    const char* what() const throw()
    {
        return ("infile format error.");
    }
};