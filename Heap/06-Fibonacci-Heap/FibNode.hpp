#ifndef __FIB_NODE__
#define __FIB_NODE__
#include <cstdio>
#include "HeapNode.hpp"
template <typename E, typename Key>
class FibNode : public HeapNode<E, Key>
{
protected:
    FibNode<E, Key> *parentNode;
    FibNode<E, Key> *childNode;
    FibNode<E, Key> *leftSibling;  // Pointer to right child
    FibNode<E, Key> *rightSibling; // Pointer to right child
    bool m;
    int d;
    void init()
    {
        parentNode = childNode = leftSibling = rightSibling = NULL;
        m = false;
        d = 0;
    }

public:
    FibNode()
    {
        init();
    }
    FibNode(E e, Key k, int id, FibNode<E, Key> *l = NULL, FibNode<E, Key> *r = NULL, FibNode<E, Key> *p = NULL, FibNode<E, Key> *c = NULL) : HeapNode<E, Key>::HeapNode(e, k, id)
    {
        init();
        parentNode = p;
        childNode = c;
        leftSibling = l;
        rightSibling = r;
    }
    // Destructor
    virtual ~FibNode()
    {
    }
    // Functions to set and return the value and key()

    const bool &mark() const { return m; }
    void setMark(bool m) { this->m = m; }
    const int &degree() const { return d; }
    void incrementDegree() { d++; }
    void decrementDegree() { d--; }
    FibNode<E, Key> *left() const { return leftSibling; }
    void setLeft(FibNode<E, Key> *l) { leftSibling = l; }
    FibNode<E, Key> *right() const { return rightSibling; }
    void setRight(FibNode<E, Key> *r) { rightSibling = r; }
    FibNode<E, Key> *parent() const { return parentNode; }
    void setParent(FibNode<E, Key> *p) { parentNode = p; }
    FibNode<E, Key> *child() const { return childNode; }
    void setChild(FibNode<E, Key> *c) { childNode = c; }
};
#endif