#ifndef __BIN_TREE__
#define __BIN_TREE__
#include "Tree.hpp"
// Binary Tree implementation
template <typename E>
class BinTree : public Tree
{
public:
    // Constructor
    BinTree() {}
    // Destructor
    virtual ~BinTree() {}
    // Inorder traversal - left->root->right.
    virtual E *inorder() const = 0;
    // Preorder traversal - root->left->right.
    virtual E *preorder() const = 0;
    // Postorder traversal - left->right->root.
    virtual E *postorder() const = 0;
};
#endif
