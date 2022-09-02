#ifndef __FIB_PRIORITY_QUEUE__
#define __FIB_PRIORITY_QUEUE__
#include <iostream>
#include <climits>
#include "FibHeap.hpp"
#include "PriorityQueue.hpp"
using namespace std;
// heapArray class
template <typename E, typename Key>
class FibPriorityQueue : public FibHeap<E, Key>, public PriorityQueue<E, Key>
{
public:
    FibPriorityQueue(int max = FibHeap<E, Key>::defaultSize) : FibHeap<E, Key>::FibHeap(max)
    {
    }
    // Insert "it" into the heapArray
    void push(const E &it, const Key &k, int id)
    {
        // cout << "START INSERT" << endl;
        this->insert(it, k, id);
        // cout << "END INSERT" << endl;
    }
    const E &top()
    {
        // cout << "START TOP" << endl;
        // Assert(this->size(), "FibHeap is empty");
        return this->getMin(); // Return deleted value
        // cout << "END TOP" << endl;
    }
    void pop()
    {
        this->extractMin(); // Return deleted value
    }
    bool empty()
    {
        return this->size() == 0;
    }
    size_t size()
    {
        return FibHeap<E, Key>::size();
    }
    void decreaseKey(int id, const Key &newKey)
    {
        FibHeap<E, Key>::decreaseKey(id, newKey);
    }
    bool isExist(int id)
    {
        return FibHeap<E, Key>::index[id] != NULL;
    }
};
#endif