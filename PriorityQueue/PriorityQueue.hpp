#ifndef __PRIORITY_QUEUE__
#define __PRIORITY_QUEUE__
#include <iostream>
#include <climits>
#include "../Heap/AHeap.hpp"
using namespace std;
// heapArray class
template <typename E, typename Comp>
class PriorityQueue : public AHeap<E, Comp>
{
private:
    int getPos(const E &key, int pos)
    {
        if (this->heapArray[pos] == key)
        {
            return pos;
        }
        else if (this->isLeaf(pos))
        {
            return -1;
        }
        int l = getPos(key, this->leftChild(pos));
        int r = getPos(key, this->rightChild(pos));
        if (l != -1 && r != -1)
        {
            return min(l, r);
        }
        else if (l != -1)
        {
            return l;
        }
        else if (r != -1)
        {
            return r;
        }
        else
        {
            return -1;
        }
    }
    void heapDeleteKey(int pos)
    {
        heapIncreaseKey(pos, INT_MAX);
        extractMax();
    }
    void heapIncreaseKey(int pos, const E &key)
    {
        Assert(key >= this->heapArray[pos], "new key is smaller than current key");
        this->heapArray[pos] = key;
        this->shiftUp(pos);
    }

public:
    PriorityQueue(int max = AHeap<E, Comp>::defaultSize) : AHeap<E, Comp>::AHeap(max)
    {
    }
    // Insert "it" into the heapArray
    void insertKey(const E &key)
    {
        this->n++;
        this->heapArray[this->n - 1] = INT_MIN;
        heapIncreaseKey(this->n - 1, key);
    }
    void deleteKey(const E &key)
    {
        int pos = getPos(key, 0);
        Assert(pos != -1, "No such key");
        heapDeleteKey(pos);
    }

    const E &getMax()
    {
        Assert(this->n > 0, "AHeap is empty");
        return this->heapArray[0]; // Return deleted value
    }
    E extractMax()
    {
        return this->removeFirst(); // Return deleted value
    }
    void increaseKey(const E &oldKey, const E &newKey)
    {
        int pos = getPos(oldKey, 0);
        Assert(pos != -1, "No such key");
        heapIncreaseKey(pos, newKey);
    }
};

template <typename E, typename Comp>
ostream &operator<<(ostream &os, PriorityQueue<E, Comp> *pq)
{
    if (pq->size() == 0)
    {
        return os;
    }
    E key = pq->removeFirst();
    os << key << " ";
    os << pq;
    pq->insertKey(key);
    return os;
}
#endif