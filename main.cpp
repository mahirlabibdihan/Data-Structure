#include "Stack/InfixToPrefix.hpp"
#include "Stack/ReversePolishNotationParser.hpp"
#include "Tree/LBST.hpp"
#include "Heap/AHeap0.hpp"
#include "Queue/AQueue.hpp"
class Comp
{
public:
    static bool prior(int a, int b)
    {
        return a > b;
    }
};
int main()
{
    Queue<int> *q = new AQueue<int>();
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    cout << q << endl;
    reverse(q);
    cout << q << endl;
}