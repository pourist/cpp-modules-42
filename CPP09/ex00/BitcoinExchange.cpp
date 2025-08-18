#include "BitcoinExchange.hpp"

Btc::Btc(char *file)
{
    (this->database).open("data.csv", std::ios::in);
    (this->inFile).open(file, std::ios::in);
    if (this->database.fail())
        throw (openDatabaseError());
    if (this->inFile.fail())
        throw(openFileError());
    parseDatabase();
    print_result();
}

Btc::~Btc(){
    this->database.close();
    this->inFile.close();
}

Btc::Btc(const Btc& src)
{
    (void)src;
}

Btc &Btc::operator=(const Btc& src)
{
    if (this != &src)
        return (*this);
    return (*this);
}


float    Btc::stofCheck(std::string strNumber, std::string line)
{
    const char *cNumber = strNumber.c_str();
    char *end;

    float fNumber = std::strtof(cNumber, &end);
    if(!isdigit(cNumber[0]) && cNumber[0] != '-')
        throw std::runtime_error("Error: bad input => " + line);
    if (*end != '\0')
        throw std::runtime_error("Error: bad input => " + line);
    else if (fNumber < 0)
        throw std::runtime_error("Error: not a positive number.");
    else if (fNumber >= (float)INT_MAX)
        throw std::runtime_error("Error: too large a number.");
    return (fNumber);
}

int   Btc::strToDate(std::string str_date, std::string line)
{
    std::istringstream  ss(str_date);
    std::string         year;
    std::string         month;
    std::string         day;
    char                *end[3];

    if (std::getline(ss, year, '-') && std::getline(ss, month, '-') && std::getline(ss, day))
    {
        if (day.empty())
            throw std::runtime_error("Error: bad input => " + line);
        int yy = std::strtol(year.c_str(), &(end[0]), 10);
        int mm = std::strtol(month.c_str(), &(end[1]), 10);
        int dd = std::strtol(day.c_str(), &(end[2]), 10);
        if (*end[0] != '\0' || *end[1] != '\0' || *end[2] != '\0')
            throw std::runtime_error("Error: bad input => " + line);
        if (mm < 1 || mm > 12 || dd < 1 || dd > 31)
            throw std::runtime_error("Error: bad input => " + line);
        return ((yy * 10000) + (mm * 100) + dd);    
    }
    else
        throw std::runtime_error("Error: bad input => " + line);
}


void    Btc::parseDatabase()
{
    std::string line, date, price;
    
    std::getline(this->database, line);
    if(line != "date,exchange_rate")
        throw(databaseFormatError());
    while (std::getline(this->database, line))
    {
        std::istringstream  ss(line);
        if (std::getline(ss, date, ',') && std::getline(ss, price))
        {
            this->priceMap.insert(std::pair<int, float>(strToDate(date, line), stofCheck(price, line)));
        }
        else
            throw (databaseFormatError());
    }
}

void    Btc::print_result()
{
    std::string date, value, line;
    
    std::getline(this->inFile, line);
    if(line != "date | value")
        throw(inFileFormatError());
    while (std::getline(this->inFile, line))
    {
        try{
            std::istringstream  ss(line);
            if (line.empty())
                continue;
            if (std::getline(ss, date, '|') && std::getline(ss, value))
            {
                if (date.empty())
                    throw std::runtime_error("Error: bad input => " + line);
                else
                    date.erase(date.size() - 1);    
                if (value.empty())
                    throw std::runtime_error("Error: bad input => " + line);
                else
                    value.erase(0, 1);
                int     date_number = strToDate(date, line);
                float   value_f = stofCheck(value, line);
                if (value_f > 1000)
                    throw std::runtime_error("Error: value is too large." );
                if (date_number < (this->priceMap).begin()->first)
                    throw   std::runtime_error("Error: no data available for " + date);
                std::map<int, float>::iterator it = this->priceMap.end(); 
                while (it-- != this->priceMap.begin())
                {
                    if ((*it).first <= date_number)
                    {
                        std::cout << date << " => " << value << " = " << (value_f * (*it).second) <<std::endl;
                        break;
                    }
                }
            }
            else
                throw std::runtime_error("Error: bad input => " + line);       
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
}
