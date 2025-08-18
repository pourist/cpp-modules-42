#include "RPN.hpp"

RPN::RPN(){
}

RPN::~RPN(){
}

RPN::RPN(char* exp){
    exp_check(exp);
}

void    RPN::exp_check(char* exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == ' ')
            continue;
        else if (isdigit(exp[i]))
        {
            if (i && isdigit(exp[i - 1]))
                throw std::runtime_error("Error: invalid number");
            this->rpnStack.push(static_cast<float>(exp[i]) - 48);
        }
        else if (exp[i] == '*' || exp[i] == '/' || exp[i] == '+' || exp[i] == '-')
        {
            if(this->rpnStack.size() < 2)
                throw std::runtime_error("Error: not enough operands");
            this->rpnStack.push(operation(exp[i]));
        }
        else
            throw std::runtime_error("Error: invalid character");
    }
    if (this->rpnStack.size() != 1)
        throw std::runtime_error("Error: invalid expression");
    std::cout << (int)this->rpnStack.top() << std::endl;
}

float    RPN::operation(char token)
{
    float b = this->rpnStack.top();
    this->rpnStack.pop();
    float a = this->rpnStack.top();
    this->rpnStack.pop();
    if (token == '*')
        return(a * b);
    else if (b && token == '/')
        return(a / b);
    else if (token == '+')
        return(a + b);
    else if (token == '-')
        return(a - b);
    else
        throw std::runtime_error("Error: division by zero");
}