#ifndef __HEAP_NODE__
#define __HEAP_NODE__
template <typename E, typename Key>
class HeapNode
{
protected:
    E it; // The node’s value
    int id;
    Key k;

public:
    HeapNode()
    {
        this->it = E();
        this->id = -1;
        this->k = -1;
    }
    HeapNode(const E &e, const Key &k, int id)
    {
        this->it = e;
        this->id = id;
        this->k = k;
    }
    // Destructor
    virtual ~HeapNode() {}
    // Functions to set and return the value and key()

    const E &element() const { return it; }
    void setElement(const E &e) { it = e; }
    const E &getId() const { return id; }
    void setId(int id) { this->id = id; }
    const Key &key() const { return k; }
    void setKey(const Key &K) { k = K; }
};
#endif