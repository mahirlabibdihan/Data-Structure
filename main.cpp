#include "Stack/InfixToPrefix.hpp"
#include "Stack/ReversePolishNotationParser.hpp"
int main()
{
    char infix[100];
    gets(infix);
    string RPN = infixToPostfix(infix);
    cout << RPN << endl;
    cout << parser(RPN) << endl;
}