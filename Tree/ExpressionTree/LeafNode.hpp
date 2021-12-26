#include "VarBinNode.hpp"
#include "Operand.hpp"
template <typename E>
class LeafNode : public VarBinNode
{ // Leaf node
private:
    Operand<E> var; // Operand value
public:
    LeafNode(const Operand<E> &val) { var = val; } // Constructor
    bool isLeaf() { return true; }                 // isLeaf for Leafnode
    Operand<E> value() { return var; }             // Return node value
    void setValue(const Operand<E> &v) { var = v; }
    void traverse() { cout << value() << " "; }
};