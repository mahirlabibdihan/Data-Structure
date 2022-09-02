#ifndef __BIN_NODE__
#define __BIN_NODE__
#include "HeapNode.hpp"
template <typename E, typename Key>
class BinNode : public HeapNode<E, Key>
{
public:
    BinNode()
    {
    }
    BinNode(E e, Key k, int id) : HeapNode<E, Key>::HeapNode(e, k, id)
    {
    }
    // Destructor
    virtual ~BinNode() {}
    // Functions to set and return the value and key()
};
#endif