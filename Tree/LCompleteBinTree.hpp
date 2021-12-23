#ifndef __L_COMPLETE_BIN_TREE_
#define __L_COMPLETE_BIN_TREE_
#include "LBinTree.hpp"
#include "../Queue/LQueue.hpp"
#include "../Deque/LDeque.hpp"
// LCompleteBinTree class
template <typename E, typename Comp>
class LCompleteBinTree : public LBinTree
{
public:
    LCompleteBinTree()
    {
    }
    ~LCompleteBinTree()
    {
    }
    // Insert "it" into the LCompleteBinTree
    void insert(const E &it)
    {
        if (root == NULL)
        {
            root = new BinNode<E>(it, NULL, NULL, NULL);
        }
        else if (root != NULL)
        {
            // Enqueue+Dequeue = O(n)
            Queue<BinNode<E> *> *q = new LQueue<BinNode<E> *>();
            q->enqueue(root);
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
                    q->clear();
                    break;
                }
            }
        }
        n++;
    }
    E removeFirst()
    {
        Assert(root != NULL, "Heap is empty");
        Deque<BinNode<E> *> *q = new LDeque<BinNode<E> *>();
        q->push_back(root);
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
        E tmp = root->element();
        if (temp == root)
        {
            delete root;
            root = NULL;
        }
        else
        {
            root->setElement(temp->element());
            if (temp->parent()->right() == NULL)
            {
                temp->parent()->setLeft(NULL);
            }
            else
            {
                temp->parent()->setRight(NULL);
            }
            delete temp;
        }
        n--;
        return tmp;
    }
};
#endif