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
    E *heap; // Pointer to the heap array
    static const int defaultSize = 10;
    int maxSize; // Maximum size of the heap
    int n;       // Number of elements now in the heap
    // Helper function to put element in its correct place
    void shiftDown(int pos)
    {
        while (!isLeaf(pos))
        { // Stop if pos is a leaf
            int j = leftChild(pos);
            int rc = rightChild(pos);
            if ((rc < n) && Comp::prior(heap[rc], heap[j]))
                j = rc; // Set j to greater child’s value
            if (Comp::prior(heap[pos], heap[j]))
                return; // Done
            swap(heap[pos], heap[j]);
            pos = j; // Move down
        }
    }
    void shiftUp(int pos)
    {
        while (pos != 0 && Comp::prior(heap[pos], heap[parent(pos)]))
        {
            swap(heap[pos], heap[parent(pos)]);
            pos = parent(pos); // Move down
        }
    }

public:
    Heap(int max = defaultSize)
    {
        maxSize = max;
        heap = new E[maxSize];
        n = 0;
    }
    Heap(E *h, int num, int max) // Constructor
    {
        heap = h;
        n = num;
        maxSize = max;
        heapify();
    }
    int size() const // Return current heap size
    {
        return n;
    }
    bool isLeaf(int pos) const // True if pos is a leaf
    {
        return (pos >= n / 2) && (pos < n);
    }
    int leftChild(int pos) const
    {
        return 2 * pos + 1;
    } // Return leftchild position
    int rightChild(int pos) const
    {
        return 2 * pos + 2;
    }                         // Return rightchild position
    int parent(int pos) const // Return parent position
    {
        return (pos - 1) / 2;
    }
    void heapify() // Heapify contents of heap
    {
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            shiftDown(i);
        }
    }
    // Insert "it" into the heap
    void insert(const E &it)
    {
        if (n == maxSize)
        {
            cout << "Heap is full" << endl;
            return;
        }
        n++;
        heap[n - 1] = it; // Start at end of heap
        // Now sift up until curr’s parent > curr
        shiftUp(n - 1);
    }
    // Remove first value
    E removeFirst()
    {
        Assert(n > 0, "Heap is empty");
        swap(heap[0], heap[--n]); // Swap first with last value
        if (n != 0)
        {
            shiftDown(0); // shiftdown new root val
        }
        return heap[n]; // Return deleted value
    }
    // Remove and return element at specified position
    E remove(int pos)
    {
        Assert((pos >= 0) && (pos < n), "Bad position");
        if (pos == (n - 1))
        {
            n--; // Last element, no work to do
        }
        else
        {
            swap(heap[pos], heap[--n]); // Swap with last value
            shiftUp(pos);
            if (n != 0)
            {
                shiftDown(pos); // Push down small key
            }
        }
        return heap[n];
    }
};
#endif