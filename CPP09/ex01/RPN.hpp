#pragma once

#include <iostream>
#include <stack>

class RPN
{
    private:
        std::stack<float>   rpnStack;

        RPN();
        RPN(const RPN& src);
        RPN &operator=(const RPN& src);
    public:
        RPN(char *exp);
        ~RPN();

        float    operation(char token);
        void    exp_check(char* exp);
};