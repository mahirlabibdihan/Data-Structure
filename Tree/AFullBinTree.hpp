#ifndef __A_COMPLETE_BIN_TREE__
#define __A_COMPLETE_BIN_TREE__
#include <iostream>
using namespace std;
#include "ABinTree.hpp"
// heap class
template <typename E>
class AFullBinTree : public ABinTree<E>
{
    void printhelp(int pos) const;
    int postorderhelp(int pos, E *arr, int idx) const;
    int preorderhelp(int pos, E *arr, int idx) const;
    int inorderhelp(int pos, E *arr, int idx) const;
public:
    AFullBinTree(int max = ABinTree<E>::defaultSize) : ABinTree<E>::ABinTree(max)
    {
    }
    AFullBinTree(E *t, int num, int max) : ABinTree<E>::ABinTree(t, num, max) // Constructor
    {
    }
    int height() const
    {
        return log2(this->n + 1) - 1;
    }
    void print() const
    {
        if (this->size() == 0)
            cout << "The Tree is empty";
        else
            printhelp(0);
        cout << endl;
    }
    // Inorder traversal - left->root->right.
    E *inorder() const
    {
        E *arr = new E[this->n];
        inorderhelp(0, arr, 0);
        return arr;
    }

    // Preorder traversal - root->left->right.
    E *preorder() const
    {
        E *arr = new E[this->n];
        preorderhelp(0, arr, 0);
        return arr;
    }

    // Postorder traversal - left->right->root.
    E *postorder() const
    {
        E *arr = new E[this->n];
        postorderhelp(0, arr, 0);
        return arr;
    }
};
template <typename E>
// Preorder print
void AFullBinTree<E>::printhelp(int pos) const
{
    if (pos >= this->n) // Empty subtree, do nothing
        return;
    cout << this->tree[pos]; // Print record

    if (this->isLeaf(pos)) // If it's leaf, no need to print its empty childs
        return;

    cout << '(';
    if (this->left(pos) < this->n)  // To avoid extra call
        printhelp(this->left(pos)); // Go left subtree
    cout << ')';

    cout << '(';
    if (this->right(pos) < this->n)  // To avoid extra call
        printhelp(this->right(pos)); // Go right subtree
    cout << ')';
}
template <typename E>
int AFullBinTree<E>::postorderhelp(int pos, E *arr, int idx) const
{
    if (pos >= this->n)
        return idx;
    if (this->left(this->pos) < this->n) // To avoid extra call
        idx = inorderhelp(this->left(pos), arr, idx);
    if (this->right(pos) < this->n) // To avoid extra call
        idx = inorderhelp(this->right(pos), arr, idx);
    arr[idx++] = this->tree[pos];
    return idx;
}
template <typename E>
int AFullBinTree<E>::preorderhelp(int pos, E *arr, int idx) const
{
    if (pos >= this->n)
        return idx;
    arr[idx++] = this->tree[pos];
    if (this->left(pos) < this->n) // To avoid extra call
        idx = inorderhelp(this->left(pos), arr, idx);
    if (this->right(pos) < this->n) // To avoid extra call
        idx = inorderhelp(this->right(pos), arr, idx);
    return idx;
}
template <typename E>
int AFullBinTree<E>::inorderhelp(int pos, E *arr, int idx) const
{
    if (pos >= this->n)
        return idx;
    if (this->left(pos) < this->n) // To avoid extra call
        idx = inorderhelp(this->left(pos), arr, idx);
    arr[idx++] = this->tree[pos];
    if (this->right(pos) < this->n) // To avoid extra call
        idx = inorderhelp(this->right(pos), arr, idx);
    return idx;
}
#endif