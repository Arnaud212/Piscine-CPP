#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstdlib>

class RPN
{
    private:
        std::stack<int> stack;

    public:
        RPN();
        RPN(RPN const &rhs);
        RPN &operator=(RPN const &rhs);
        ~RPN();

        void expression(char *av);
        bool isOperator(char c);
        void calcul(char c);
};

#endif