#ifndef __FIB_HEAP__
#define __FIB_HEAP__
#include <iostream>
#include "FibNode.hpp"
#include "Heap.hpp"
#include <climits>
#include <cmath>
#include <cstdio>
using namespace std;
#define Assert(val, s)                             \
    if (!(val))                                    \
    {                                              \
        cout << "Assertion Failed: " << s << endl; \
        exit(-1);                                  \
    }
// FibHeap class
template <typename E, typename Key>
class FibHeap : public Heap<E, Key>
{
private:
    void operator=(const FibHeap &) {} // Protect assignment
    FibHeap(const FibHeap &) {}        // Protect copy constructor
public:
    FibNode<E, Key> *root; // Root of the LBinTree
    FibNode<E, Key> **index;
    int nodecount; // Number of nodes in the LBinTree
public:
    static const int defaultSize = 10;
    void consolidate()
    {
        int max_degree = (log(nodecount) / log(2)) + 2;
        FibNode<E, Key> *A[max_degree];
        for (int i = 0; i < max_degree; i++)
        {
            A[i] = NULL;
        }
        FibNode<E, Key> *w = this->root;
        do
        {
            FibNode<E, Key> *x = w;
            int d = x->degree();
            FibNode<E, Key> *next = x->right();
            // Assert(max_degree > d, "Index out of bound");
            while (A[d] != NULL /*&& A[d] != x*/)
            {
                FibNode<E, Key> *y = A[d];
                if (y->key() < x->key())
                {
                    swap(x, y);
                }
                if (next == y)
                {
                    next = y->right();
                }
                if (this->root == y)
                {
                    this->root = y->right();
                }
                link(y, x);
                A[d] = NULL;
                d++;
            }
            A[d] = x;
            w = next;
            // w = x->right();
        } while (w != this->root);

        this->root = NULL;
        for (int i = 0; i < max_degree; i++)
        {
            if (A[i] != NULL)
            {
                A[i]->setLeft(A[i]);
                A[i]->setRight(A[i]);
                if (this->root == NULL)
                {
                    this->root = A[i];
                }
                else
                {
                    insertIntoList(A[i], this->root);
                    if (A[i]->key() < this->root->key())
                    {
                        this->root = A[i];
                    }
                }
            }
        }

        // for (int i = 0; i < max_degree; i++)
        // {
        //     if (A[i] != NULL)
        //     {
        //         if (A[i]->key() < this->root->key())
        //         {
        //             this->root = A[i];
        //         }
        //     }
        // }
    }
    void link(FibNode<E, Key> *y, FibNode<E, Key> *x)
    {
        // Make y child of x
        removeFromList(y);
        y->setLeft(y);
        y->setRight(y);
        y->setParent(x);
        if (x->child() == NULL)
        {
            x->setChild(y);
        }
        else
        {
            insertIntoList(y, x->child());
        }
        x->incrementDegree();
        y->setMark(false);
    }

    // Cuts the link between x and its parent y
    // Makes x a root
    void cut(FibNode<E, Key> *x, FibNode<E, Key> *y)
    {
        // Remove x fromy the child list of y
        if (x == x->right())
        {
            y->setChild(NULL);
        }
        else
        {
            if (x == y->child())
            {
                y->setChild(x->right());
            }
            removeFromList(x);
        }

        y->decrementDegree();

        // Add x to the root list of H
        x->setLeft(x);
        x->setRight(x);
        if (this->root == NULL)
        {
            this->root == x;
        }
        else
        {
            insertIntoList(x, this->root);
        }
        x->setParent(NULL);
        x->setMark(false);
    }
    void cascadingCut(FibNode<E, Key> *y)
    {
        // cout << "CASCADING CUT" << endl;
        FibNode<E, Key> *z = y->parent();
        if (z != NULL)
        {
            if (y->mark() == false)
            {
                y->setMark(true); // First cut
            }
            else // 2nd cut
            {
                cut(y, z);
                cascadingCut(z);
            }
        }
    }
    // To left
    // void concat(FibNode<E, Key> *RL1, FibNode<E, Key> *RL2)
    // {
    //     if (RL1 == NULL or RL2 == NULL)
    //     {
    //         return;
    //     }
    //     RL1->left()->setRight(RL2);
    //     RL2->left()->setRight(RL1);
    //     FibNode<E, Key> *RL1_left = RL1->left();
    //     FibNode<E, Key> *RL2_left = RL2->left();
    //     RL1->setLeft(RL2_left);
    //     RL2->setLeft(RL1_left);
    // }
    void insertIntoList(FibNode<E, Key> *new_node, FibNode<E, Key> *root)
    {
        root->left()->setRight(new_node);
        new_node->setRight(root);
        new_node->setLeft(root->left());
        root->setLeft(new_node);
    }
    void removeFromList(FibNode<E, Key> *z)
    {
        z->left()->setRight(z->right());
        z->right()->setLeft(z->left());
    }

public:
    FibHeap(int max = 0)
    {
        root = NULL;
        nodecount = 0;
        index = new FibNode<E, Key> *[max];
    }
    ~FibHeap()
    {
        // delete index[];
    }
    void buildHeap()
    {
    }

    int size() const { return this->nodecount; }
    // Insert "it" into the FibHeap

    // void unite(FibHeap<E, Key> *H2)
    // {
    //     FibHeap<E, Key> *H1 = this;
    //     concat(H1->root, H2->root);
    //     if (H1->root == NULL or (H2->root != NULL and H2->root->key() < H1->root->key()))
    //     {
    //         H1->root = H2->root;
    //     }
    //     H1->nodecount += H2->nodecount;
    // }
    void insert(const E &it, const Key &k, int id)
    {
        FibNode<E, Key> *new_node = new FibNode<E, Key>(it, k, id);
        index[id] = new_node;
        new_node->setLeft(new_node);
        new_node->setRight(new_node);
        if (this->root == NULL)
        {
            this->root = new_node;
        }
        else
        {
            insertIntoList(new_node, this->root);
            if (new_node->key() < this->root->key())
            {
                this->root = new_node;
            }
        }
        this->nodecount++;
    }
    void decreaseKey(int id, const Key &k)
    {
        FibNode<E, Key> *x = this->index[id];
        // Assert(x != NULL, "No such key()");
        // Assert(k < x->key(), "New key() has less priority then current key()");
        x->setKey(k);
        FibNode<E, Key> *y = x->parent();
        if (y != NULL and x->key() < y->key())
        {
            cut(x, y);
            cascadingCut(y);
        }
        // Set the root
        if (x->key() < this->root->key())
        {
            this->root = x;
        }
    }
    // void removeNode(FibNode<E, Key> *x)
    // {
    //     decreaseKey(x, {INT_MAX, x->element()->second});
    //     extractMin();
    // }

    // No need to change key()
    void remove(FibNode<E, Key> *x)
    {
        FibNode<E, Key> *y = x->parent();
        if (y != NULL)
        {
            cut(x, y);
            cascadingCut(y);
        }
        this->root = x;
        extractMin();
    }

    E extractMin()
    {
        // Assert(this->root != NULL, "Heap is empty. Can't remove.");
        FibNode<E, Key> *z = this->root;

        // Add all child of z to root list
        FibNode<E, Key> *x = z->child();
        index[z->getId()] = NULL;
        while (x != NULL)
        {
            FibNode<E, Key> *next = x->right();
            if (x == x->right())
            {
                next = NULL;
                z->setChild(NULL);
            }
            else
            {
                removeFromList(x);
            }
            x->setLeft(x);
            x->setRight(x);
            insertIntoList(x, z);
            x->setParent(NULL);
            x = next;
        }
        E it = z->element();

        // Since we have concatinated in the left
        removeFromList(z);
        if (z == z->right())
        {
            this->root = NULL;
        }
        else
        {
            this->root = z->right();
            consolidate();
        }

        delete z;
        this->nodecount--;
        return it;
    }
    bool isExist(int id)
    {
        return index[id] != NULL;
    }
    const E &getMin()
    {
        // Assert(this->root != NULL, "Heap is empty");
        return this->root->element();
    }
};
#endif