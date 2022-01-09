#include "Stack/InfixToPrefix.hpp"
#include "Stack/ReversePolishNotationParser.hpp"
#include "Tree/LBST.hpp"
int main()
{
    // char infix[100];
    // gets(infix);
    // string RPN = infixToPostfix(infix);
    // cout << RPN << endl;
    // cout << parser(RPN) << endl;
    int a[] = {1, 7, 3, 5, 2, 5};
    int n = sizeof(a) / sizeof(a[0]);
    sort<int, int>(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}