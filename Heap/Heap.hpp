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
    virtual E getFirst() = 0;
    // Remove and return element at specified position
    // virtual E remove(int pos) = 0;
};
template <typename E, typename Comp>
void removeKth(Heap<E, Comp> *h, int k)
{
    if (k <= h->size() && k > 0)
    {
        E tmp = h->removeFirst();
        removeKth(h, k - 1);
        if (k > 1)
            h->insert(tmp);
    }
}
template <typename E, typename Comp>
E getKth(Heap<E, Comp> *h, int k)
{
    if (k <= h->size())
    {
        if (k > 1)
        {
            E tmp = h->removeFirst();
            E tmp2 = getKth(h, k - 1);
            h->insert(tmp);
            return tmp2;
        }
        else
        {
            return h->getFirst();
        }
    }
}
template <typename E, typename Comp>
ostream &operator<<(ostream &os, Heap<E, Comp> *h)
{
    if (h->size() == 0)
    {
        return os;
    }
    E key = h->removeFirst();
    os << key << " ";
    os << h;
    h->insert(key);
    return os;
}
#ifndef __HEAP_SORT__
#define __HEAP_SORT__
template <typename E, typename Comp>
void shiftDown(E A[], int n, int pos)
{
    while (!((pos >= n / 2) && (pos < n)))
    { // Stop if pos is a leaf
        int largest = pos;
        int lc = 2 * pos + 1;
        int rc = 2 * pos + 2;
        if ((lc < n) && Comp::prior(A[lc], A[largest]))
        {
            largest = lc; // Set lc to greater child’s value
        }
        if ((rc < n) && Comp::prior(A[rc], A[largest]))
        {
            largest = rc; // Set rc to greater child’s value
        }
        if (largest == pos)
            return;
        swap(A[pos], A[largest]); // Swap with child
        pos = largest;            // Move down
    }
}
// O(n)->Tighter Bound
template <typename E, typename Comp>
void buildHeap(E A[], int n) // Heapify contents of heapArray
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        shiftDown<E, Comp>(A, n, i);
    }
}
template <typename E, typename Comp>
void heapsort(E A[], int n)
{
    buildHeap<E, Comp>(A, n);
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        swap(A[0], A[i]);
        // call max heapify on the reduced heap
        shiftDown<E, Comp>(A, i, 0);
    }
}
#endif
#endif