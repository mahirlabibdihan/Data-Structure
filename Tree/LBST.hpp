#ifndef __L_BST__
#define __L_BST__
#include <iostream>
using namespace std;
#include "LBinTree.hpp"
#include "BSTNode.hpp"

// Binary Search Tree implementation
template <typename Key, typename E>
class LBST : public LBinTree<E>
{
private:
    BinNode<E> *eraseKthSmallest(BinNode<E> *root, int k)
    {
        // remove(kthSmallest(this->root, k)->element());
        if (root == NULL) // Empty tree
        {
            return NULL;
        }
        // cout << root->element() << endl;
        if (root->left() != NULL)
        {
            root->setLeft(eraseKthSmallest(root->left(), k));
        }

        k--;
        if (k == 0)
        {
            // Found: remove it
            BinNode<E> *temp = root;
            if (root->left() == NULL && root->right() == NULL)
            {
                root = NULL; // No children, so point to NULL
            }
            else if (root->left() == NULL)
            {
                root = root->right(); // No left child,so point to right
            }
            else if (root->right() == NULL)
            {
                root = root->left(); // No right child,so point to left
            }
            else
            {
                temp = getMax(root->left()); // Inorder predecessor
                ((BSTNode<Key, E> *)root)->setKey(((BSTNode<Key, E> *)temp)->key());
                root->setElement(temp->element());
                root->setLeft(deleteMax(root->left()));
            }
            delete temp;
            this->nodecount--;
            return root;
        }
        if (root->right() != NULL)
        {
            root->setRight(eraseKthSmallest(root->right(), k));
        }
        return root;
    }
    BinNode<E> *inserthelp(BinNode<E> *root, const Key &k, const E &e);
    BinNode<E> *deleteMin(BinNode<E> *root);
    BinNode<E> *getMin(BinNode<E> *root) const;
    BinNode<E> *deleteMax(BinNode<E> *root);
    BinNode<E> *getMax(BinNode<E> *root) const;
    BinNode<E> *removehelp(BinNode<E> *root, const Key &k);
    bool findhelp(BinNode<E> *root, const Key &k) const;

public:
    LBST() {}  // Constructor
    ~LBST() {} // Destructor

    // Insert a record into the tree.
    // k: Key value of the record.
    // e: The record to insert.
    void insert(const Key &k, const E &e)
    {
        this->root = inserthelp(this->root, k, e);
        this->nodecount++; // Increasing total node count
    }

    // Remove a record from the tree.
    // k: Key value of the record to remove
    // Return: The record removed, or NULL if there is none.
    bool remove(const Key &k)
    {
        if (findhelp(this->root, k)) // First find it
        {
            this->root = removehelp(this->root, k);
            this->nodecount--;
            return true;
        }
        return false;
    }

    // Return Record with key value 'k', NULL if none exist.
    // If multiple nodes match 'k', return an arbitrary one.
    bool find(const Key &k) const
    {
        return findhelp(this->root, k);
    }
};
template <typename Key, typename E>
BinNode<E> *LBST<Key, E>::inserthelp(BinNode<E> *root, const Key &k, const E &e)
{
    if (root == NULL) // Empty subtree: create node
        return new BSTNode<Key, E>(k, e, NULL, NULL);
    if (k < ((BSTNode<Key, E> *)root)->key())
    { // 'k' is smaller than current node, so go left
        root->setLeft(inserthelp(root->left(), k, e));
    }
    else
    { // 'k' is greater than current node, so go right
        root->setRight(inserthelp(root->right(), k, e));
    }
    return root; // Return tree with node inserted
}
template <typename Key, typename E>
BinNode<E> *LBST<Key, E>::deleteMin(BinNode<E> *root)
{
    if (root->left() == NULL)
    { // Found min
        // min has either right child or no child
        if (root->right() == NULL) // No child
        {
            return NULL;
        }
        else // Has right child
        {
            return root->right();
        }
    }
    else
    { // Continue left
        root->setLeft(deleteMin(root->left()));
        return root;
    }
}
template <typename Key, typename E>
BinNode<E> *LBST<Key, E>::getMin(BinNode<E> *root) const
{
    if (root->left() == NULL)
    { // Found min
        return root;
    }
    else
    { // Continue left
        return getMin(root->left());
    }
}
template <typename Key, typename E>
BinNode<E> *LBST<Key, E>::deleteMax(BinNode<E> *root)
{
    if (root->right() == NULL)
    { // Found max
        // max has either left child or no child
        if (root->left() == NULL) // No child
        {
            return NULL;
        }
        else // Has left child
        {
            return root->left();
        }
    }
    else
    { // Continue right
        root->setRight(deleteMax(root->right()));
        return root;
    }
}
template <typename Key, typename E>
BinNode<E> *LBST<Key, E>::getMax(BinNode<E> *root) const
{
    if (root->right() == NULL)
    { // Found max
        return root;
    }
    else
    { // Continue right
        return getMax(root->right());
    }
}
template <typename Key, typename E>
BinNode<E> *LBST<Key, E>::removehelp(BinNode<E> *root, const Key &k)
{
    if (root == NULL) // Empty tree
    {
        return NULL;
    }
    if (k < ((BSTNode<Key, E> *)root)->key())
    {
        // 'k' is smaller than current key, so go left
        root->setLeft(removehelp(root->left(), k)); // Check left
    }
    else if (k > ((BSTNode<Key, E> *)root)->key())
    {
        // 'k' is greater than current key, so go right
        root->setRight(removehelp(root->right(), k)); // Check right
    }
    else
    { // Found: remove it
        BinNode<E> *temp = root;
        if (root->left() == NULL && root->right() == NULL)
        {
            root = NULL; // No children, so point to NULL
        }
        else if (root->left() == NULL)
        {
            root = root->right(); // No left child,so point to right
        }
        else if (root->right() == NULL)
        {
            root = root->left(); // No right child,so point to left
        }
        else
        {
            // Both children are non-empty
            // We need to replace this node with inorder successor or predecessor
            // Or we can choose based on which subtree is bigger
            // if(leftSubTree>rightSubTree) {replace with inorder predecessor}
            // else {replace with inorder successor}
            // In this way the tree will remain balanced
            // temp = getMin(root->right());    // Inorder Successor
            temp = getMax(root->left()); // Inorder predecessor
            ((BSTNode<Key, E> *)root)->setKey(((BSTNode<Key, E> *)temp)->key());
            root->setElement(temp->element());
            // root->setRight(deleteMin(root->right()));
            root->setLeft(deleteMax(root->left()));
            // removehelp(root->left(),temp->element()z)
        }
        delete temp; // Deallocating memory after removing node
    }
    return root;
}
template <typename Key, typename E>
bool LBST<Key, E>::findhelp(BinNode<E> *root, const Key &k) const
{
    if (root == NULL)
    {
        return false; // 'k' is not in the tree or empty tree
    }
    if (k < ((BSTNode<Key, E> *)root)->key())
    {
        // 'k' is smaller than current key
        return findhelp(root->left(), k); // Check left
    }
    else if (k > ((BSTNode<Key, E> *)root)->key())
    {
        // 'k' is greater than current key
        return findhelp(root->right(), k); // Check right
    }
    else
    { // Found it
        return true;
    }
}
template <typename Key, typename E>
void sort(E arr[], int n)
{
    LBST<Key, E> *bst = new LBST<Key, E>();

    // O(nlogn)
    for (int i = 0; i < n; i++)
    {
        bst->insert(arr[i], arr[i]);
    }
    // O(n)
    E *newArr = bst->inorder();
    for (int i = 0; i < n; i++)
    {
        arr[i] = newArr[i];
    }
    delete bst;
}
#endif
LBST<int, int> *buildTree(int tree[], int n)
{
    LBST<int, int> *bst = new LBST<int, int>();
    for (int i = 0; i < n; i++)
    {
        bst->insert(tree[i], i);
    }
    return bst;
}