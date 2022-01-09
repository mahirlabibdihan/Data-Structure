#include "AStack.hpp"

int toDigit(char n)
{
    return n - '0';
}
int toChar(int n)
{
    return n + '0';
}
// bool isDigit(char n)
// {
//     return n >= '0' && n <= '9';
// }
// bool isOperator(char c)
// {
//     return c == '+' || c == '-' || c == '*' || c == '/';
// }
int parser(string RPN)
{
    Stack<int> *operand = new AStack<int>();
    for (int i = 0; RPN[i] != '\0'; i++)
    {
        if (isDigit(RPN[i]))
        {
            operand->push(toDigit(RPN[i]));
        }
        else if (isOperator(RPN[i]))
        {
            int op2 = operand->pop();
            int op1 = operand->pop();
            switch (RPN[i])
            {
            case '+':
                operand->push(op1 + op2);
                break;
            case '-':
                operand->push(op1 - op2);
                break;
            case '*':
                operand->push(op1 * op2);
                break;
            case '/':
                operand->push(op1 / op2);
                break;
            default:
                operand->push(op1);
                operand->push(op2);
                break;
            };
            // cout << operand->topValue() << endl;
        }
    }
    return operand->pop();
}
