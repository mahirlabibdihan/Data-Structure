#include "Queue/AQueue.hpp"

int main()
{
    Queue<int> *q = new AQueue<int>();
    q->enqueue(1);
    q->enqueue(2);
    reverse(q);
    cout << q->dequeue() << endl;
    cout << q->dequeue() << endl;
}