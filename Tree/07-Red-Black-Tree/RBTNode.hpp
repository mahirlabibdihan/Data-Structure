#ifndef __RBT_NODE__
#define __RBT_NODE__
#define BLACK 0
#define RED 1
// Simple binary tree node implementation
template <typename Key, typename E>
class RBTNode
{
private:
    int color, st_size;
    E it; // The node’s value
    Key k;
    RBTNode<Key, E> *parent_node;
    RBTNode<Key, E> *left_child;  // Pointer to left_child child
    RBTNode<Key, E> *right_child; // Pointer to right child

public:
    // Two constructors -- with and without initial values
    RBTNode(Key K = Key(), E e = E(), int c = BLACK, RBTNode<Key, E> *l = NULL, RBTNode<Key, E> *r = NULL, RBTNode<Key, E> *p = NULL)
    {
        k = K;
        st_size = 0;
        it = e;
        color = c;
        left_child = l;
        right_child = r;
        parent_node = p;
    }
    ~RBTNode() {} // Destructor

    // Functions to set and return the children
    const Key &key() const { return k; }
    void setKey(const Key &K) { k = K; }
    RBTNode<Key, E> *left() const { return left_child; }
    void setLeft(RBTNode<Key, E> *lc) { left_child = lc; }
    RBTNode<Key, E> *right() const { return right_child; }
    void setRight(RBTNode<Key, E> *rc) { right_child = rc; }
    const E &element() const { return it; }
    void setElement(const E &e) { it = e; }
    RBTNode<Key, E> *parent() const { return parent_node; }
    void setParent(RBTNode<Key, E> *p) { parent_node = p; }
    const int getColor() const { return color; }
    const void setColor(const int c) { color = c; }
    const bool isRed() const { return color == RED; }
    const void makeRed() { color = RED; }
    const void makeBlack() { color = BLACK; }
    const void incrementSize(int sz = 1) { st_size += sz; }
    const void decrementSize(int sz = 1) { st_size -= sz; }
    const int getSize() const { return st_size; }
    const void setSize(const int sz) { st_size = sz; }
};
#endif