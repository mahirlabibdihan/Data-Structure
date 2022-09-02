#ifndef __BINARY_HEAP__
#define __BINARY_HEAP__
#include "Heap.hpp"
#include <queue>
#include <vector>
#include "BinNode.hpp"
using namespace std;

template <typename E, typename Key>
class BinHeap : public Heap<E, Key>
{
private:
    void operator=(const BinHeap &) {} // Protect assignment
    BinHeap(const BinHeap &) {}        // Protect copy constructor
public:
    int *index;
    BinNode<E, Key> **heapArray; // Pointer to the heapArray array
    static const int defaultSize = 10;
    int maxSize; // Maximum size of the heapArray
    int n;       // Number of elements now in the heapArray
    // Helper function to put element in its correct place
    // O(logh)
    void shiftDown(int pos)
    {
        while (!isLeaf(pos))
        { // Stop if pos is a leaf
            int smallest = pos;
            int lc = leftChild(pos);
            int rc = rightChild(pos);
            if ((lc <= n) && heapArray[lc]->key() < heapArray[smallest]->key())
            {
                smallest = lc; // Set lc to greater child’s value
            }
            if ((rc <= n) && heapArray[rc]->key() < heapArray[smallest]->key())
            {
                smallest = rc; // Set rc to greater child’s value
            }
            if (smallest == pos)
                return;
            swap(index[heapArray[pos]->getId()], index[heapArray[smallest]->getId()]);
            swap(heapArray[pos], heapArray[smallest]); // Swap with child
            pos = smallest;                            // Move down
        }
    }
    void shiftUp(int pos)
    {
        while (pos != 1 && heapArray[pos]->key() < heapArray[parent(pos)]->key())
        {
            swap(index[heapArray[pos]->getId()], index[heapArray[parent(pos)]->getId()]);
            swap(heapArray[pos], heapArray[parent(pos)]); // Swap with parent
            pos = parent(pos);                            // Move up
        }
    }
    bool isLeaf(int pos) const // True if pos is a leaf
    {
        return (pos > n / 2) && (pos <= n);
    }
    int leftChild(int pos) const
    {
        return pos << 1;
    } // Return leftchild position
    int rightChild(int pos) const
    {
        return pos << 1 | 1;
    }                         // Return rightchild position
    int parent(int pos) const // Return parent position
    {
        return pos >> 1;
    }
    void decreaseKey(int pos, const Key &k)
    {
        // cout << pos << endl;
        Assert(k < this->heapArray[pos]->key(), "new key has less priority than current key");
        // cout << k << " " << this->heapArray[pos]->key() << endl;
        this->heapArray[pos]->setKey(k);
        // cout << k << " " << this->heapArray[pos]->key() << endl;
        this->shiftUp(pos);
    }
    // Remove and return element at specified position
    E *remove(int id)
    {
        int pos = index[id];
        Assert(pos != -1, "No such key()");
        // Assert((pos >= 1) && (pos <= n), "Bad position");
        if (pos == n)
        {
            n--; // Last element, no work to do
        }
        else
        {
            swap(index[heapArray[pos]->getId()], index[heapArray[n]->getId()]);
            swap(heapArray[pos], heapArray[n--]); // Swap with last value
            // In next step, it will be either shiftUp or shiftDown.
            // Only one operation will be executed
            // Percolation
            if (n > 0)
            {
                shiftUp(pos);   // Push up large key()
                shiftDown(pos); // Push down small key()
            }
        }
        return heapArray[n + 1]->element();
    }

public:
    BinHeap(int max = defaultSize)
    {
        maxSize = max + 1;
        heapArray = new BinNode<E, Key> *[maxSize];
        n = 0;
        index = new int[max];
    }
    ~BinHeap()
    {
        delete[] heapArray;
    }
    int size() const // Return current heapArray size
    {
        return n;
    }
    // Insert "it" into the heapArray
    void insert(const E &it, const Key &k, int id)
    {
        n++;
        index[id] = n;
        heapArray[n] = new BinNode<E, Key>(it, k, id); // Start at end of heapArray
        // Now sift up until curr’s parent > curr
        shiftUp(n);
    }

    // Remove first value: O(logn)
    E extractMin()
    {
        Assert(n > 0, "Heap is empty");
        swap(index[heapArray[1]->getId()], index[heapArray[n]->getId()]);
        swap(heapArray[1], heapArray[n]); // Swap first with last value
        n--;
        if (n > 0)
        {
            shiftDown(1); // shiftdown new root val
        }
        index[heapArray[n + 1]->getId()] = -1;
        return heapArray[n + 1]->element(); // Return deleted value
    }
    const E &getMin()
    {
        // Assert(n > 0, "Heap is empty");
        return heapArray[1]->element();
    }
};
#endif