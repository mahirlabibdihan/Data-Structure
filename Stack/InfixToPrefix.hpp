#include "AStack.hpp"
//Function to return precedence of operators
bool isDigit(char n)
{
    return n >= '0' && n <= '9';
}
bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// The main function to convert infix expression
//to postfix expression
string infixToPostfix(char *s)
{

    AStack<char> st; //For stack operations, we are using C++ built in stack
    string RPN;

    for (int i = 0; s[i] != '\0'; i++)
    {
        char c = s[i];

        // If the scanned character is
        // an operand, add it to output string.
        if (isDigit(c))
            RPN += c;

        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (c == '(')
            st.push('(');

        // If the scanned character is an ‘)’,
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')')
        {
            while (st.topValue() != '(')
            {
                RPN += st.topValue();
                st.pop();
            }
            st.pop();
        }

        //If an operator is scanned
        else if (isOperator(c))
        {
            while (st.length() > 0 && prec(s[i]) <= prec(st.topValue()))
            {
                RPN += st.topValue();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (st.length() > 0)
    {
        RPN += st.topValue();
        st.pop();
    }

    return RPN;
}