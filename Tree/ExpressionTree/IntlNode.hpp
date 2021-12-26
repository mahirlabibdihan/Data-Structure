#include "VarBinNode.hpp"
#include "Operator.hpp"
class IntlNode : public VarBinNode
{ // Internal node
private:
    VarBinNode *lc; // Left child
    VarBinNode *rc; // Right child
    Operator opx;   // Operator value
public:
    IntlNode(const Operator &op, VarBinNode *l = NULL, VarBinNode *r = NULL)
    {
        opx = op;
        lc = l;
        rc = r;
    }                                 // Constructor
    bool isLeaf() { return false; }   // isLeaf for IntlNode
    VarBinNode *left() { return lc; } // Left child
    void setLeft(VarBinNode *l) { lc = l; }
    VarBinNode *right() { return rc; } // Right child
    void setRight(VarBinNode *r) { rc = r; }
    Operator value() { return opx; }               // Value
    void setValue(const Operator &op) { opx = op; } // Value
    void traverse()
    { // Traversal behavior for internal nodes
        if (left() != NULL)
            left()->traverse();
        cout << value() << " ";
        if (right() != NULL)
            right()->traverse();
    }
};