#include "Stack/InfixToPrefix.hpp"
#include "Stack/ReversePolishNotationParser.hpp"
#include "Tree/LBST.hpp"
#include "Heap/AHeap0.hpp"
#include "Queue/AQueue.hpp"
#include "Stack/AStack.hpp"
class Comp
{
public:
    static bool prior(const int &a, const int &b)
    {
        return a > b;
    }
};
int main()
{
    Stack<int> *s = new AStack<int>();
    s->push(1123);
    s->push(123);
    s->push(23);
    cout << s << endl;
}