#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

enum    scalarType
{
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
    INVALID,
};

class  ScalarConverter
{
    private:
        ScalarConverter();
        ~ ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
        ScalarConverter &operator=(const ScalarConverter &src);

        static  int find_type(const std::string& par);
    public:
        static  void convert(const std::string &par);
};

#endif