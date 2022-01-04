#ifndef __HEAP__
#define __HEAP__
#include <iostream>
using namespace std;
#define Assert(val, s)                             \
    if (!(val))                                    \
    {                                              \
        cout << "Assertion Failed: " << s << endl; \
        exit(-1);                                  \
    }
// heap class
template <typename E, typename Comp>
class Heap
{
protected:
    void operator=(const Heap &) {} // Protect assignment
    Heap(const Heap &) {}           // Protect copy constructor
public:
    Heap() {}
    virtual ~Heap() {}
    virtual int size() const = 0; // Return current heap size
    virtual void buildHeap() = 0; // Heapify contents of heap
    // Insert "it" into the heap
    virtual void insert(const E &it) = 0;
    // Remove first value
    virtual E removeFirst() = 0;
    // Remove and return element at specified position
    // virtual E remove(int pos) = 0;
};
template <typename E, typename Comp>
ostream &operator<<(ostream &os, Heap<E, Comp> *pq)
{
    if (pq->size() == 0)
    {
        return os;
    }
    E key = pq->removeFirst();
    os << key << " ";
    os << pq;
    pq->insert(key);
    return os;
}
#endif