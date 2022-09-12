#ifndef __RBT__
#define __RBT__
#include <iostream>
using namespace std;
#include "RBTNode.hpp"
#define Assert(val, s)                             \
    if (!(val))                                    \
    {                                              \
        cout << "Assertion Failed: " << s << endl; \
        exit(-1);                                  \
    }

// Binary Search Tree implementation
template <typename Key, typename E>
class RBT
{
private:
    RBTNode<Key, E> *getMin(RBTNode<Key, E> *x) const
    {
        while (x->left() != nil)
        {
            x = x->left();
        }
        return x;
    }
    RBTNode<Key, E> *findHelp(const Key &k) const
    {
        RBTNode<Key, E> *x = this->root;
        while (x != nil and k != x->key())
        {
            if (k < x->key())
            {
                x = x->left();
            }
            else
            {
                x = x->right();
            }
        }
        return x;
    }
    void transplant(RBTNode<Key, E> *u, RBTNode<Key, E> *v)
    {
        if (u->parent() == nil)
        {
            this->root = v;
        }
        else if (u == u->parent()->left())
        {
            u->parent()->setLeft(v);
        }
        else
        {
            u->parent()->setRight(v);
        }
        v->setParent(u->parent());
    }
    void insertFixup(RBTNode<Key, E> *z)
    {
        while (z->parent()->getColor() == RED)
        {
            if (z->parent() == z->parent()->parent()->left()) // father is left child of grandfather
            {
                RBTNode<Key, E> *y = z->parent()->parent()->right(); // z's uncle y
                if (y->getColor() == RED)                            // father and uncle is red
                {
                    // Make grandfather red
                    z->parent()->parent()->setColor(RED);
                    // Father and uncle black
                    z->parent()->setColor(BLACK);
                    y->setColor(BLACK);

                    // Fixup grandfather
                    z = z->parent()->parent();
                }
                else // Father red, uncle black, grandfather black
                {
                    if (z == z->parent()->right()) // z is right child of father
                    {
                        // L-R
                        z = z->parent();
                        leftRotate(z);
                    }
                    // z is left child of father
                    // L-L
                    z->parent()->setColor(BLACK);
                    z->parent()->parent()->setColor(RED);
                    rightRotate(z->parent()->parent());
                }
            }
            else // Father is right child of grandfather
            {
                // same as then clause with “right” and “left” exchanged
                RBTNode<Key, E> *y = z->parent()->parent()->left(); // uncle
                if (y->getColor() == RED)
                {
                    z->parent()->setColor(BLACK);
                    y->setColor(BLACK);
                    z->parent()->parent()->setColor(RED);
                    z = z->parent()->parent();
                }
                else
                {
                    // R-L
                    if (z == z->parent()->left())
                    {
                        z = z->parent();
                        rightRotate(z);
                    }
                    // R-R
                    z->parent()->setColor(BLACK);
                    z->parent()->parent()->setColor(RED);
                    leftRotate(z->parent()->parent());
                }
            }
        }
        this->root->setColor(BLACK);
    }
    void insertHelp(const Key &k, const E &e)
    {
        RBTNode<Key, E> *z = new RBTNode<Key, E>(k, e);
        RBTNode<Key, E> *y = nil;
        RBTNode<Key, E> *x = this->root;
        while (x != nil)
        {
            y = x;
            if (z->key() < x->key())
            {
                x->incrementSize();
                x = x->left();
            }
            else
            {
                x->incrementSize();
                x = x->right();
            }
        }
        z->setParent(y);
        if (y == nil)
        {
            this->root = z;
        }
        else if (z->key() < y->key())
        {
            y->setLeft(z);
        }
        else
        {
            y->setRight(z);
        }
        z->setLeft(nil);
        z->setRight(nil);
        z->setColor(RED);
        z->incrementSize();

        insertFixup(z);
    }

    void leftRotate(RBTNode<Key, E> *x)
    {
        RBTNode<Key, E> *y = x->right();
        Assert(y != nil, "ERROR: NIL ON LEFT ROTATE");

        x->setRight(y->left());
        if (y->left() != nil)
        {
            y->left()->setParent(x);
        }
        y->setParent(x->parent());
        // cout << ":" << y->parent() << " " << nil << endl;
        if (x->parent() == nil)
        {
            // cout << "CHANGE ROOT" << x->element() << endl;
            this->root = y;
        }
        else if (x == x->parent()->left())
        {
            x->parent()->setLeft(y);
        }
        else
        {
            x->parent()->setRight(y);
        }
        y->setLeft(x);
        x->setParent(y);

        x->setSize(x->left()->getSize() + x->right()->getSize() + 1);
        y->setSize(y->left()->getSize() + y->right()->getSize() + 1);
    }
    void rightRotate(RBTNode<Key, E> *y)
    {
        RBTNode<Key, E> *x = y->left();
        Assert(x != nil, "ERROR: NIL ON RIGHT ROTATE");
        y->setLeft(x->right());
        if (x->right() != nil)
        {
            x->right()->setParent(y);
        }
        x->setParent(y->parent());
        if (y->parent() == nil)
        {
            this->root = x;
        }
        else if (y == y->parent()->right())
        {
            y->parent()->setRight(x);
        }
        else
        {
            y->parent()->setLeft(x);
        }
        x->setRight(y);
        y->setParent(x);

        y->setSize(y->left()->getSize() + y->right()->getSize() + 1);
        x->setSize(x->left()->getSize() + x->right()->getSize() + 1);
    }
    // Fixup will be called on a double black node
    void removeFixup(RBTNode<Key, E> *x)
    {
        while (x != this->root and !x->isRed())
        {
            if (x == x->parent()->left())
            {
                RBTNode<Key, E> *w = x->parent()->right();
                if (w->isRed())
                {
                    w->makeBlack();
                    x->parent()->makeRed();
                    leftRotate(x->parent());
                    w = x->parent()->right();
                }
                if (!(w->left())->isRed() and !(w->right())->isRed())
                {
                    w->makeRed();
                    x = x->parent();
                }
                else
                {
                    if (!(w->right())->isRed())
                    {
                        (w->left())->makeBlack();
                        w->makeRed();
                        rightRotate(w);
                        w = x->parent()->right();
                    }
                    w->setColor(x->parent()->getColor());
                    x->parent()->setColor(BLACK);
                    (w->right())->setColor(BLACK);
                    leftRotate(x->parent());
                    x = this->root;
                }
            }
            else
            {
                // same as then clause with “right” and “left” exchanged
                RBTNode<Key, E> *w = x->parent()->left();
                if (w->isRed())
                {
                    w->makeBlack();
                    x->parent()->makeRed();
                    rightRotate(x->parent());
                    w = x->parent()->left();
                }
                if (!(w->right())->isRed() and !(w->left())->isRed())
                {
                    w->makeRed();
                    x = x->parent();
                }
                else
                {
                    if (!(w->left())->isRed())
                    {
                        w->right()->makeBlack();
                        w->makeRed();
                        leftRotate(w);
                        w = x->parent()->left();
                    }
                    w->setColor(x->parent()->getColor());
                    x->parent()->setColor(BLACK);
                    (w->left())->setColor(BLACK);
                    rightRotate(x->parent());
                    x = this->root;
                }
            }
        }
        x->setColor(BLACK);
    }

    void removeHelp(RBTNode<Key, E> *z)
    {
        RBTNode<Key, E> *y = z;
        RBTNode<Key, E> *x; // z's ultimate location
        bool was_y_red = y->isRed();

        // If y is black, removing it will decrease a black
        // We can increase a black by making x black
        // But if x is already black, it will be a double black
        // Need to fix this
        if (z->left() == nil)
        {
            x = z->right();
            transplant(z, x);
        }
        else if (z->right() == nil)
        {
            x = z->left();
            transplant(z, x);
        }
        else
        {
            y = this->getMin(z->right()); // Inorder successor
            was_y_red = y->isRed();
            x = y->right();
            if (y->parent() == z)
            {
                x->setParent(y);
            }
            else
            {
                transplant(y, y->right());
                y->setRight(z->right());
                y->right()->setParent(y);
            }
            transplant(z, y);
            y->setLeft(z->left());
            y->left()->setParent(y);
            y->setColor(z->getColor());
            y->setSize(z->getSize());
        }

        delete z;
        for (RBTNode<Key, E> *it = x->parent(); it != nil; it = it->parent())
        {
            it->decrementSize();
        }
        if (!was_y_red)
        {
            removeFixup(x);
        }
    }

protected:
    RBTNode<Key, E> *nil;  // Root of the BinTree
    RBTNode<Key, E> *root; // Root of the Tree
public:
    RBT()
    {
        this->root = nil = new RBTNode<Key, E>();
        nil->setColor(BLACK);
    } // Constructor
    virtual ~RBT()
    {
    } // Destructor
    bool remove(const Key &k)
    {
        RBTNode<Key, E> *z = findHelp(k);
        if (z != nil) // First find it
        {
            removeHelp(z);
            // removeHelp(root, k);
            return true;
        }
        return false;
    }
    bool insert(const Key &k, const E &e)
    {
        RBTNode<Key, E> *z = findHelp(k);
        if (z == nil)
        {
            insertHelp(k, e);
            return true;
        }
        return false;
    }
    E find(const Key &k) const
    {
        RBTNode<Key, E> *e = findHelp(k);
        if (e != nil)
        {
            return e->element();
        }
        return -1;
    }
};
#endif
