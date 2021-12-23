#ifndef __A_HEAP__
#define __A_HEAP__
// heap class
template <typename E>
class ABinTree
{
protected:
    E *tree; // Pointer to the heap array
    static const int defaultSize = 10;
    int maxSize;               // Maximum size of the heap
    int n;                     // Number of elements now in the heap
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

public:
    ABinTree(int max = defaultSize)
    {
        maxSize = max;
        tree = new E[maxSize];
        n = 0;
    }
    ABinTree(E *t, int num, int max) // Constructor
    {
        tree = t;
        n = num;
        maxSize = max;
    }
    int size() const // Return current heap size
    {
        return n;
    }
};
#endif