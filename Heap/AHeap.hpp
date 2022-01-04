#ifndef __A_HEAP__
#define __A_HEAP__
#include "Heap.hpp"
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
    void shiftDown(int pos)
    {
        while (!isLeaf(pos))
        { // Stop if pos is a leaf
            int j = leftChild(pos);
            int rc = rightChild(pos);
            if ((rc < n) && Comp::prior(heapArray[rc], heapArray[j]))
                j = rc; // Set j to greater child’s value
            if (Comp::prior(heapArray[pos], heapArray[j]))
                return; // Done
            swap(heapArray[pos], heapArray[j]);
            pos = j; // Move down
        }
    }
    void shiftUp(int pos)
    {
        while (pos != 0 && Comp::prior(heapArray[pos], heapArray[parent(pos)]))
        {
            swap(heapArray[pos], heapArray[parent(pos)]);
            pos = parent(pos); // Move down
        }
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
    void expand()
    {
        E *temp = new E[2 * maxSize];
        for (int i = 0; i < 2 * maxSize; i++)
        {
            temp[i] = heapArray[i];
        }
        maxSize *= 2;
        delete[] heapArray;
        heapArray = temp;
    }

public:
    AHeap(int max = defaultSize)
    {
        maxSize = max;
        heapArray = new E[maxSize];
        n = 0;
    }
    AHeap(E *h, int num, int max) // Constructor
    {
        heapArray = h;
        n = num;
        maxSize = max;
        buildHeap();
    }
    int size() const // Return current heapArray size
    {
        return n;
    }
    void buildHeap() // Heapify contents of heapArray
    {
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            shiftDown(i);
        }
    }
    // Insert "it" into the heapArray
    void insert(const E &it)
    {
        if (n == maxSize)
        {
            expand();
        }
        n++;
        heapArray[n - 1] = it; // Start at end of heapArray
        // Now sift up until curr’s parent > curr
        shiftUp(n - 1);
    }
    // Remove first value
    E removeFirst()
    {
        Assert(n > 0, "Heap is empty");
        swap(heapArray[0], heapArray[--n]); // Swap first with last value
        if (n != 0)
        {
            shiftDown(0); // shiftdown new root val
        }
        return heapArray[n]; // Return deleted value
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
        Assert((pos >= 0) && (pos < n), "Bad position");
        if (pos == (n - 1))
        {
            n--; // Last element, no work to do
        }
        else
        {
            swap(heapArray[pos], heapArray[--n]); // Swap with last value
            // In next step, it will be either shiftUp or shiftDown.
            // Only one operation will be executed
            // Percolation
            shiftUp(pos);
            if (n != 0)
            {
                shiftDown(pos); // Push down small key
            }
        }
        return heapArray[n];
    }
};
#ifndef __HEAP_SORT__
#define __HEAP_SORT__
template <typename E, typename Comp>
void heapsort(E A[], int n)
{                                                   // Heapsort
    Heap<E, Comp> *H = new AHeap<E, Comp>(A, n, n); // Build the heapArray
    for (int i = 0; i < n; i++)                     // Now sort
    {
        A[n - i - 1] = H->removeFirst(); // Place maxval at end
    }
}
#endif
#endif