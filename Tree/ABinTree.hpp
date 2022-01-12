#ifndef __A_HEAP__
#define __A_HEAP__
// heap class
// We have to use some dummy values where the node is empty
/*
If we start indexing from 1 instead of 0.
Left Child = 2*i = i<<2
Right Child = 2*i+1 = i<<2|1
Parent = i/2 = i>>2
*/
template <typename E>
class ABinTree
{
protected:
    E *tree; // Pointer to the heap array
    static const int defaultSize = 10;
    int maxSize; // Maximum size of the heap
    int n;       // Number of elements now in the heap
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
    int leftSibling(int pos)
    {
        Assert(r % 2 == 0, "No left sibling");
        return pos - 1;
    }
    int rightSibling(int pos)
    {
        Assert(r % 2 != 0, "No right sibling");
        return pos + 1;
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