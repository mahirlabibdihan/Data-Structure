#ifndef __BIN_NODE__
#define __BIN_NODE__
// Simple binary tree node implementation
template <typename E>
class BinNode
{
protected:
    E it; // The node’s value
    BinNode<E> *parentNode;
    BinNode<E> *leftChild;  // Pointer to leftChild child
    BinNode<E> *rightChild; // Pointer to right child
public:
    // Two constructors -- with and without initial values
    BinNode()
    {
        it = E();
        parentNode = leftChild = rightChild = NULL;
    }
    BinNode(E e, BinNode<E> *p = NULL, BinNode<E> *l = NULL, BinNode<E> *r = NULL)
    {
        it = e;
        parentNode = p;
        leftChild = l;
        rightChild = r;
    }
    // Destructor
    virtual ~BinNode() {}
    // Functions to set and return the value and key
    const E &element() const { return it; }
    void setElement(const E &e) { it = e; }

    // Functions to set and return the children
    BinNode<E> *left() const { return leftChild; }
    void setLeft(BinNode<E> *lc) { leftChild = lc; }
    BinNode<E> *right() const { return rightChild; }
    void setRight(BinNode<E> *rc) { rightChild = rc; }
    BinNode<E> *parent() const { return parentNode; }
    void setParent(BinNode<E> *p) { parentNode = p; }
    // Return: true if it is a leaf, false otherwise
    bool isLeaf() const { return (leftChild == NULL) && (rightChild == NULL); }
};
#endif