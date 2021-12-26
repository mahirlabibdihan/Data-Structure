#ifndef __L_HEAP__
#define __L_HEAP__
#include <iostream>
#include "BinNode.hpp"
#include "../Queue/LQueue.hpp"
#include "../Deque/LDeque.hpp"
#include "../Tree/LBinTree.hpp"
using namespace std;
#define Assert(val, s)                             \
    if (!(val))                                    \
    {                                              \
        cout << "Assertion Failed: " << s << endl; \
        exit(-1);                                  \
    }
// LHeap class
template <typename E, typename Comp>
class LHeap : public LBinTree<E>
{
protected:
    // O(logn)
    void shiftDown(BinNode<E> *root)
    {
        BinNode<E> *largest = root;        //initialize root as largest element
        BinNode<E> *left = root->left();   //left child
        BinNode<E> *right = root->right(); //right child
        // If left child is larger than root
        if (left != NULL)
        {
            if (Comp::prior(left->element(), largest->element()))
            {
                largest = left;
            }
        }
        // If right child is larger than largest so far
        if (right != NULL)
        {
            if (Comp::prior(right->element(), largest->element()))
            {
                largest = right;
            }
        }

        if (largest != root) //largest elemnt jodi root na hoy..
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
    }
    ~LHeap()
    {
    }
    void heapify(BinNode<E> *root) // Heapify contents of Heap
    {
        // If a node doesn't have left or right child,then it's a leaf. Otherwise it's non-leaf
        if (root != NULL)
        {
            if (root->left == NULL && root->right == NULL)
            {
                return; // Leaf
            }
            heapify(root->left);
            shiftDown(root); // called heapify on all the non-leaf elements of the heap
            heapify(root->right);
        }
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
    // Remove and return element at specified position
    E remove(int pos)
    {
        Assert((pos >= 0) && (pos < n), "Bad position");
        if (pos == (n - 1))
        {
            n--; // Last element, no work to do
        }
        else
        {
            swap(heap[pos], heap[--n]); // Swap with last value
            shiftUp(pos);
            if (n != 0)
            {
                shiftDown(pos); // Push down small key
            }
        }
        return heap[n];
    }
};
#endif