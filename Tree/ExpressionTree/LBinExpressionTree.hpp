#ifndef __L_BIN_EXPRESSION_TREE__
#define __L_BIN_EXPRESSION_TREE__
// Binary LBinExpressionTree implementation
#include "VarBinNode.hpp"
template <typename E>
class LBinExpressionTree
{
public:
    VarBinNode *root;
    // Constructor
    LBinExpressionTree()
    {
        root = NULL;
    }
    // Destructor
    ~LBinExpressionTree() {}
};
#endif
