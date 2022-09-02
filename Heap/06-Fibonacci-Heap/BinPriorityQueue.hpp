#ifndef __BIN_PRIORITY_QUEUE__
#define __BIN_PRIORITY_QUEUE__
#include <iostream>
#include <climits>
#include "BinHeap.hpp"
#include "PriorityQueue.hpp"
using namespace std;
// heapArray class
template <typename E, typename Key>
class BinPriorityQueue : public BinHeap<E, Key>, public PriorityQueue<E, Key>
{

public:
    BinPriorityQueue(int max = BinHeap<E, Key>::defaultSize) : BinHeap<E, Key>::BinHeap(max)
    {
    }
    // Insert "it" into the heapArray
    void push(const E &it, const Key &k, int id)
    {
        // cout << "START INSERT" << endl;
        this->insert(it, k, id);
        // cout << "END INSERT" << endl;
    }
    void deleteKey(int id)
    {
        this->remove(id);
    }
    const E &top()
    {
        Assert(this->n > 0, "BinHeap is empty");
        return this->getMin(); // Return deleted value
    }
    void pop()
    {
        this->extractMin(); // Return deleted value
    }
    void decreaseKey(int id, const Key &newKey)
    {
        int pos = this->index[id];
        Assert(pos != -1, "No such key()");
        BinHeap<E, Key>::decreaseKey(pos, newKey);
        // Assert(this->heapArray[this->index[id]]->element() = this->heapArray[this->index[id]]->key(), "ERROR");
        Assert(this->heapArray[this->index[id]]->getId() == id, "ERROR ID" + to_string(id));
        // Assert(this->heapArray[this->index[id]]->key() == newKey, "ERROR " + to_string(id) + " " + to_string(newKey) + " " + to_string(this->heapArray[this->index[id]]->key()) + " " + to_string(pos));
    }
    bool isExist(int id)
    {
        return BinHeap<E, Key>::index[id] != -1;
    }
    bool empty()
    {
        return this->n == 0;
    }
    size_t size()
    {
        return this->n;
    }
};
#endif