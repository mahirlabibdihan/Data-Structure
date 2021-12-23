#ifndef __L_BIN_TREE__
#define __L_BIN_TREE__
#include <iostream>
using namespace std;
#include "BinNode.hpp"
#include "BinTree.hpp"
// Binary Tree implementation
template <typename E>
class LBinTree : public BinTree<E>
{
protected:
    BinNode<E> *root; // Root of the LBinTree
    int nodecount;    // Number of nodes in the LBinTree
private:
    // Private "helper" functions
    void clearhelp(BinNode<E> *root);
    // Preorder print
    void printhelp(BinNode<E> *root) const;
    int heighthelp(BinNode<E> *root) const;
    int counthelp(BinNode<E> *root) const;
    int postorderhelp(BinNode<E> *root, E *arr, int idx) const;
    int preorderhelp(BinNode<E> *root, E *arr, int idx) const;
    int inorderhelp(BinNode<E> *root, E *arr, int idx) const;

public:
    // Constructor
    LBinTree()
    {
        root = NULL;
        nodecount = 0;
    }
    // Destructor
    virtual ~LBinTree() { clearhelp(root); }
    // Reinitialize tree
    void clear()
    {
        clearhelp(root);
        root = NULL; // Because root now has garbage value, so setting it to NULL
        nodecount = 0;
    }

    // Return the number of nodes in the tree.
    int size() const { return nodecount; }
    int height() const
    {
        return heighthelp(root);
    }

    // Print the contents of the tree.
    void print() const
    {
        if (root == NULL)
            cout << "The Tree is empty";
        else
            printhelp(root);
        cout << endl;
    }

    // Inorder traversal - left->root->right.
    E *inorder() const
    {
        E *arr = new E[nodecount];
        inorderhelp(root, arr, 0);
        return arr;
    }

    // Preorder traversal - root->left->right.
    E *preorder() const
    {
        E *arr = new E[nodecount];
        preorderhelp(root, arr, 0);
        return arr;
    }

    // Postorder traversal - left->right->root.
    E *postorder() const
    {
        E *arr = new E[nodecount];
        postorderhelp(root, arr, 0);
        return arr;
    }
    template <typename T>
    friend ostream &operator<<(ostream &os, LBinTree<T> *t);
};
template <typename T>
ostream &operator<<(ostream &os, LBinTree<T> *t)
{
    t->print();
    return os;
}
template <typename E>
// Private "helper" functions
void LBinTree<E>::clearhelp(BinNode<E> *root)
{
    if (root == NULL) // Empty subtree, do nothing
        return;
    if (root->left() != NULL)     // To avoid extra call
        clearhelp(root->left());  // Clear left subtree
    if (root->right() != NULL)    // To avoid extra call
        clearhelp(root->right()); // Clear right subtree
    delete root;                  // Deallocate memory
}
template <typename E>
// Preorder print
void LBinTree<E>::printhelp(BinNode<E> *root) const
{
    if (root == NULL) // Empty subtree, do nothing
        return;
    cout << root->element(); // Print record

    if (root->isLeaf()) // If it's leaf, no need to print its empty childs
        return;

    cout << '(';
    if (root->left() != NULL)    // To avoid extra call
        printhelp(root->left()); // Go left subtree
    cout << ')';

    cout << '(';
    if (root->right() != NULL)    // To avoid extra call
        printhelp(root->right()); // Go right subtree
    cout << ')';
}
template <typename E>
int LBinTree<E>::heighthelp(BinNode<E> *root) const
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        /* compute the depth of each subtree */
        int lDepth = heighthelp(root->left());
        int rDepth = heighthelp(root->right());
        /* use the larger one */
        return max(lDepth, rDepth) + 1;
    }
}
template <typename E>
int LBinTree<E>::counthelp(BinNode<E> *root) const
{
    if (root == NULL)
        return 0; // Nothing to count
    return 1 + count(root->left()) + count(root->right());
}
template <typename E>
int LBinTree<E>::postorderhelp(BinNode<E> *root, E *arr, int idx) const
{
    if (root == NULL)
        return idx;
    if (root->left() != NULL) // To avoid extra call
        idx = postorderhelp(root->left(), arr, idx);
    if (root->right() != NULL) // To avoid extra call
        idx = postorderhelp(root->right(), arr, idx);
    arr[idx++] = root->element();
    return idx;
}
template <typename E>
int LBinTree<E>::preorderhelp(BinNode<E> *root, E *arr, int idx) const
{
    if (root == NULL)
        return idx;
    arr[idx++] = root->element();
    if (root->left() != NULL) // To avoid extra call
        idx = preorderhelp(root->left(), arr, idx);
    if (root->right() != NULL) // To avoid extra call
        idx = preorderhelp(root->right(), arr, idx);
    return idx;
}
template <typename E>
int LBinTree<E>::inorderhelp(BinNode<E> *root, E *arr, int idx) const
{
    if (root == NULL)
        return idx;
    if (root->left() != NULL) // To avoid extra call
        idx = inorderhelp(root->left(), arr, idx);
    arr[idx++] = root->element();
    if (root->right() != NULL) // To avoid extra call
        idx = inorderhelp(root->right(), arr, idx);
    return idx;
}

#endif
