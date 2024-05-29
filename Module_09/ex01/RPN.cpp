#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const &rhs)
{
    *this = rhs;
}

RPN &RPN::operator=(RPN const &rhs)
{
    stack = rhs.stack;
    return (*this);
}

RPN::~RPN() {}

bool RPN::isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return (true);
    return (false);
}

void RPN::calcul(char c)
{
    int res;

    if (stack.size() < 2)
        {
            std::cout << "Error" << std::endl;
            exit(EXIT_FAILURE);
        }
    int a = stack.top();
    stack.pop();
    int b = stack.top();
    stack.pop();
    if (c == '+')
        res = b + a;
    else if (c == '-')
        res = b - a;
    else if (c == '*')
        res = b * a;
    else
    {
        if (a == 0)
        {
            std::cout << "Error: cannot divide by zero!" << std::endl;
            exit(EXIT_FAILURE);
        }
        res = b / a;
    }
    stack.push(res);
}

void RPN::expression(char *str)
{
    int i = 0;

    while (str[i])
    {
        while (std::isspace(str[i]))
            i++;
        if (std::isdigit(str[i]))
        {
            if (std::isdigit(str[i + 1]))
            {
                std::cout << "Error: numbers larger than 9 not allowed" << std::endl;
                exit(EXIT_FAILURE);
            }
            stack.push(str[i] - '0');
        }
        else if (isOperator(str[i]))
            calcul(str[i]);
        else if (str[i] == '\0')
            break;
        else
        {
            std::cout << "Error" << std::endl;
            exit(EXIT_FAILURE);
        }
        i++;
    }
    if (stack.size() != 1)
    {
        std::cout << "Error" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << stack.top() << std::endl;
}