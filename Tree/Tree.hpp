#ifndef __TREE__
#define __TREE__
// Binary Tree implementation
template <typename E>
class Tree
{
private:
    void operator=(const Tree &) {} // Protect assignment
    Tree(const Tree &) {}           // Protect copy constructor
public:
    // Constructor
    Tree() {}
    // Destructor
    virtual ~Tree() {}
    // Reinitialize tree
    virtual void clear() = 0;
    // Return the number of nodes in the tree.
    virtual int size() const = 0;
    virtual int height() const = 0;
    // Print the contents of the tree.
    virtual void print() const = 0;
};
#endif
