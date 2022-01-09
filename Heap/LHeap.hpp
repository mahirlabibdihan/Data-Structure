#ifndef __L_HEAP__
#define __L_HEAP__
#include <iostream>
#include "BinNode.hpp"
#include "Heap.hpp"
#include "../Queue/LQueue.hpp"
#include "../Deque/LDeque.hpp"
using namespace std;
#define Assert(val, s)                             \
    if (!(val))                                    \
    {                                              \
        cout << "Assertion Failed: " << s << endl; \
        exit(-1);                                  \
    }
// LHeap class
template <typename E, typename Comp>
class LHeap : public Heap<E, Comp>
{
private:
    BinNode<E> *root; // Root of the LBinTree
    int nodecount;    // Number of nodes in the LBinTree
protected:
    // O(logn)
    void shiftDown(BinNode<E> *root)
    {
        BinNode<E> *largest = root;        //initialize root as largest priority
        BinNode<E> *left = root->left();   //left child
        BinNode<E> *right = root->right(); //right child
        // If left child is larger than root
        if (left != NULL && Comp::prior(left->element(), largest->element()))
        {
            largest = left;
        }
        // If right child is larger than largest so far
        if (right != NULL && Comp::prior(right->element(), largest->element()))
        {
            largest = right;
        }
        if (largest != root) // If largest is not root, then it will go down
        {
            // Swap
            E temp = largest->element();
            largest->setElement(root->element());
            root->setElement(temp);
            shiftDown(largest); //recursively heapify
        }
    }
    // O(logn)
    void shiftUp(BinNode<E> *node)
    {
        if (node == this->root)
        {
            return;
        }
        if (Comp::prior(node->element(), node->parent()->element()))
        {
            E temp = node->element();
            node->setElement(node->parent()->element());
            node->parent()->setElement(temp);
            shiftUp(node->parent());
        }
    }

public:
    LHeap(int max = 0)
    {
        root = NULL;
        nodecount = 0;
    }
    LHeap(E *h, int num, int max = 0) // Constructor
    {
        root = NULL;
        nodecount = num;
        for (int i = 0; i < num; i++)
        {
            this->insert(h[i]);
        }
    }
    ~LHeap()
    {
    }
    int size() const { return this->nodecount; }
    void heapify(BinNode<E> *root) // Heapify contents of Heap
    {
        // If a node doesn't have left or right child,then it's a leaf. Otherwise it's non-leaf
        if (root != NULL)
        {
            if (root->left() == NULL && root->right() == NULL)
            {
                return; // Leaf
            }
            heapify(root->left());
            shiftDown(root); // called heapify on all the non-leaf elements of the heap
            heapify(root->right());
        }
    }
    void buildHeap()
    {
        heapify(this->root);
    }
    // Insert "it" into the LHeap
    void insert(const E &it)
    {
        if (this->root == NULL)
        {
            this->root = new BinNode<E>(it, NULL, NULL, NULL);
        }
        else
        {
            // Enqueue+Dequeue = O(n)
            Queue<BinNode<E> *> *q = new LQueue<BinNode<E> *>();
            q->enqueue(this->root);
            while (q->length() > 0)
            {
                BinNode<E> *temp = q->dequeue();
                if (temp->left() != NULL)
                {
                    q->enqueue(temp->left());
                }
                else
                {
                    temp->setLeft(new BinNode<E>(it, temp, NULL, NULL));
                    shiftUp(temp->left()); // O(logn)
                    q->clear();
                    break;
                }
                if (temp->right() != NULL)
                {
                    q->enqueue(temp->right());
                }
                else
                {
                    temp->setRight(new BinNode<E>(it, temp, NULL, NULL));
                    shiftUp(temp->right());
                    q->clear();
                    break;
                }
            }
        }
        this->nodecount++;
    }
    E removeFirst()
    {
        Assert(this->root != NULL, "Heap is empty");
        Deque<BinNode<E> *> *q = new LDeque<BinNode<E> *>();
        q->push_back(this->root);
        BinNode<E> *temp;
        while (q->length() > 0)
        {
            temp = q->pop_front();
            if (temp->left() != NULL)
            {
                q->push_back(temp->left());
            }
            if (temp->right() != NULL)
            {
                q->push_back(temp->right());
            }
        }
        E tmp = this->root->element();
        if (temp == this->root)
        {
            delete temp;
            this->root = NULL;
        }
        else
        {
            this->root->setElement(temp->element());
            if (temp->parent()->right() == NULL)
            {
                temp->parent()->setLeft(NULL);
            }
            else
            {
                temp->parent()->setRight(NULL);
            }
            delete temp;
            shiftDown(this->root);
        }
        this->nodecount--;
        return tmp;
    }
};
#ifndef __HEAP_SORT__
#define __HEAP_SORT__
template <typename E, typename Comp>
void heapsort(E A[], int n)
{                                                   // Heapsort
    Heap<E, Comp> *H = new LHeap<E, Comp>(A, n, n); // Build the heap
    for (int i = n - 1; i >= 0; i--)                // Now sort
    {
        A[i] = H->removeFirst(); // Place maxval at end
    }
    delete H;
}
#endif
#endif