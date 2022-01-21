#ifndef __A_HEAP__
#define __A_HEAP__
#include "Heap.hpp"
#include <queue>
#include <vector>
using namespace std;
/*
If we start indexing from 1 instead of 0.
Left Child = 2*i = i<<2
Right Child = 2*i+1 = i<<2|1
Parent = i/2 = i>>2
n/2<i<n -> leaf
*/
// heapArray class
template <typename E, typename Comp>
class AHeap : public Heap<E, Comp>
{
protected:
    E *heapArray; // Pointer to the heapArray array
    static const int defaultSize = 10;
    int maxSize; // Maximum size of the heapArray
    int n;       // Number of elements now in the heapArray
    // Helper function to put element in its correct place
    // O(logh)
    void shiftDown(int pos)
    {
        while (!isLeaf(pos))
        { // Stop if pos is a leaf
            int largest = pos;
            int lc = leftChild(pos);
            int rc = rightChild(pos);
            if ((lc <= n) && Comp::prior(heapArray[lc], heapArray[largest]))
            {
                largest = lc; // Set lc to greater child’s value
            }
            if ((rc <= n) && Comp::prior(heapArray[rc], heapArray[largest]))
            {
                largest = rc; // Set rc to greater child’s value
            }
            if (largest == pos)
                return;
            swap(heapArray[pos], heapArray[largest]); // Swap with child
            pos = largest;                            // Move down
        }
    }
    void shiftUp(int pos)
    {
        while (pos != 1 && Comp::prior(heapArray[pos], heapArray[parent(pos)]))
        {
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
    void expand()
    {
        E *temp = new E[2 * maxSize - 1];
        for (int i = 0; i < maxSize; i++)
        {
            temp[i] = heapArray[i];
        }
        maxSize = 2 * maxSize - 1;
        delete[] heapArray;
        heapArray = temp;
    }
    // Remove and return element at specified position
    /*
    Case 1:
                1
            2       8
          3   5  10  11
        6
    If we want to delete 10, we have to replace it with 6.
                1
            2       8
          3   5   6   11
    Since 6 is smaller than 8 we have to shift it up.
                1
            2       6
          3   5   8   11

    Case 2:
                1
            2       8
          3   5  10  11
        6
    If we want to delete 2, we have to replace it with 6.
                1
            6       8
          3   5  10   11
    Since 6 is greater than 3 and 5 we have to shift it down.
                1
            3       8
          6   5  10   11
    */
    E remove(int pos)
    {
        Assert((pos >= 1) && (pos <= n), "Bad position");
        if (pos == n)
        {
            n--; // Last element, no work to do
        }
        else
        {
            swap(heapArray[pos], heapArray[n--]); // Swap with last value
            // In next step, it will be either shiftUp or shiftDown.
            // Only one operation will be executed
            // Percolation
            if (n > 0)
            {
                shiftUp(pos);   // Push up large key
                shiftDown(pos); // Push down small key
            }
        }
        return heapArray[n + 1];
    }

public:
    AHeap(int max = defaultSize)
    {
        maxSize = max + 1;
        heapArray = new E[maxSize];
        n = 0;
    }
    AHeap(E *h, int num, int max) // Constructor
    {
        heapArray = h;
        n = num;
        maxSize = max + 1;
        buildHeap();
    }
    ~AHeap()
    {
        delete[] heapArray;
    }
    int size() const // Return current heapArray size
    {
        return n;
    }
    // O(n)->Tighter Bound
    void buildHeap() // Heapify contents of heapArray
    {
        for (int i = n / 2; i >= 1; i--)
        {
            shiftDown(i);
        }
    }
    // Insert "it" into the heapArray
    void insert(const E &it)
    {
        if (n == maxSize - 1)
        {
            expand();
        }
        n++;
        heapArray[n] = it; // Start at end of heapArray
        // Now sift up until curr’s parent > curr
        shiftUp(n);
    }
    // Remove first value: O(logn)
    E removeFirst()
    {
        Assert(n > 0, "Heap is empty");
        swap(heapArray[1], heapArray[n--]); // Swap first with last value
        if (n > 0)
        {
            shiftDown(1); // shiftdown new root val
        }
        return heapArray[n + 1]; // Return deleted value
    }
    E getFirst()
    {
        Assert(n > 0, "Heap is empty");
        return heapArray[1];
    }
};
#ifndef __HEAP_SORT__
#define __HEAP_SORT__
template <typename E, typename Comp>
void heapsort(E A[], int n)
{
    // O(n)                                       // Heapsort
    Heap<E, Comp> *H = new AHeap<E, Comp>(A, n, n); // Build the heapArray
    // O(nlogn)
    for (int i = n - 1; i >= 0; i--) // Now sort
    {
        // O(logn)
        A[i] = H->removeFirst(); // Place maxval at end
    }
    delete H;
}
#endif
#endif