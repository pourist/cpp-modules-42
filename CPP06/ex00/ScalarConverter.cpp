#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits.h>
#include <string.h>
#include <cstdlib>
#include <iomanip>

ScalarConverter:: ScalarConverter()
{
}

ScalarConverter::~ ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    *this = src;
}

ScalarConverter  &ScalarConverter::operator=(const ScalarConverter &src)
{
    (void)src;
    return (*this);
}

int ScalarConverter::find_type(const std::string& arg)
{
    char    *end;
    long long int    long_number;
    const char *str = arg.c_str();
    if (arg.empty())
        return (INVALID);
    if (arg.length() == 1 && !isdigit(arg[0]))
        return (CHAR);
    long_number = std::strtoll(str, &end, 10);
    if (*end == '\0')
    {
        if (long_number >= INT_MIN && long_number <= INT_MAX)
            return (INT);
        return (INVALID);
    }
    std::strtof(str, &end);
    if (strcmp(end, "f") == 0)
        return (FLOAT);
    std::strtod(str, &end);
    if (*end == '\0')
        return (DOUBLE);
    return (INVALID);
}

void    ScalarConverter::convert(const std::string& arg)
{
    int int_val = 0;
    double  double_val = 0;
    char    c;
    float   float_val = 0;

    switch(find_type(arg))
    {
        case (CHAR):
            c = arg[0];
            int_val = static_cast<int>(c);
            double_val = static_cast<double>(c);
            float_val = static_cast<float>(c);
            break;
        case (INT):
            int_val = std::strtoll(arg.c_str(), NULL, 10);
            c = static_cast<char>(int_val);
            double_val = static_cast<double>(int_val);
            float_val = static_cast<float>(int_val);
            break;
        case (FLOAT):
            float_val = std::strtof(arg.c_str(), NULL);
            c = static_cast<char>(float_val);
            double_val = static_cast<double>(float_val);
            int_val = static_cast<int>(float_val);
            break;
        case (DOUBLE):
            double_val = std::strtof(arg.c_str(), NULL);
            c = static_cast<char>(double_val);
            float_val = static_cast<float>(double_val);
            int_val = static_cast<int>(double_val);
            break;
        default:
            std::cout << "Invalid input\n";
            return;
    }
    if (arg == "nan" || arg == "+inf" || arg == "-inf" || arg == "inf" ||
        arg == "-nan" || arg == "+inff" || arg == "-inff" || arg == "inf" ||
        arg == "nanf" || arg == "+nanf" || arg == "-nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (!arg.empty() && arg[arg.length() - 1] == 'f')
            std::cout << "float: " << arg << std::endl;
        else
            std::cout << "float: " << arg << "f" << std::endl;
        std::cout << "double: " << arg << std::endl;
        return;
    }
	if (int_val < 0 || int_val > 127)
		std::cout << "char: impossible" << std::endl;
	else if (int_val < 32 || int_val > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
    if (float_val >= (float)INT_MIN && float_val <= (float)INT_MAX)
        std::cout << "int: " << int_val << std::endl;
    else
        std::cout << "int: impossible" << std::endl; 
    std::cout << "float: " << float_val << "f" << std::endl;
    std::cout << "double: " << double_val << std::endl;
}