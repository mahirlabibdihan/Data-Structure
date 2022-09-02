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
        // cout << "ROOT" << this->root->element() << endl;
        this->root->setColor(BLACK);
    }
    void insertHelp(const Key &k, const E &e)
    {
        RBTNode<Key, E> *z = new RBTNode<Key, E>(k, e);
        RBTNode<Key, E> *y = nil;
        RBTNode<Key, E> *x = this->root;
        while (x != nil)
        {
            // cout << "->" << x->key() << " " << z->key() << endl;
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
    // void swapValues(RBTNode<Key, E> *u, RBTNode<Key, E> *v)
    // {
    //     int tmp_k = u->key();
    //     u->setKey(v->key());
    //     v->setKey(tmp_k);

    //     int tmp_e = u->element();
    //     u->setElement(v->element());
    //     v->setElement(tmp_e);
    // }

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
    // RBTNode<Key, E> *findReplacement(RBTNode<Key, E> *z)
    // {
    //     if (z->left() != nil)
    //     {
    //         return z->left();
    //     }
    //     else if (z->right() != nil)
    //     {
    //         return z->right();
    //     }
    //     else
    //     {
    //         return this->getMin(z->right());
    //     }
    // }

    // Fixup will be called on a double black node
    void removeFixup(RBTNode<Key, E> *x)
    {
        // cout << x->key() << " " << x->parent()->key() << endl;
        // Assert(x != nil, "ERROR:NIL ON REMOVE FIXUP");
        while (x != this->root and !x->isRed())
        {
            if (x == x->parent()->left())
            {
                // cout << "CASE 1" << endl;
                RBTNode<Key, E> *w = x->parent()->right();
                // cout << w->key() << endl;
                if (w->isRed())
                {
                    // cout << "RED" << endl;
                    w->makeBlack();
                    x->parent()->makeRed();
                    leftRotate(x->parent());
                    w = x->parent()->right();
                }
                // cout << "Passed" << endl;
                if (!(w->left())->isRed() and !(w->right())->isRed())
                {
                    // cout << "CASE 3" << endl;
                    w->makeRed();
                    x = x->parent();
                }
                else
                {
                    // cout << "CASE 4" << endl;
                    if (!(w->right())->isRed())
                    {
                        // cout << "CASE 5" << endl;
                        (w->left())->makeBlack();
                        w->makeRed();
                        // cout << "START ROTATE" << endl;
                        rightRotate(w);
                        // cout << "END ROTATE" << endl;
                        w = x->parent()->right();
                    }
                    // cout << "CASE 6" << endl;
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
                // cout << "CASE 2" << endl;
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

    // void removeHelp(RBTNode<Key, E> *z, const Key &k)
    // {
    //     if (z == nil) // Empty tree
    //     {
    //         return;
    //     }
    //     if (k < z->key())
    //     {
    //         z->decrementSize();
    //         removeHelp(z->left(), k);
    //     }
    //     else if (k > z->key())
    //     {
    //         z->decrementSize();
    //         removeHelp(z->right(), k);
    //     }
    //     else
    //     {                       // Found: remove it
    //         RBTNode<Key, E> *x; // z's ultimate location
    //         RBTNode<Key, E> *y = z;
    //         bool was_y_red = y->isRed();
    //         if (z->left() == nil && z->right() == nil)
    //         {
    //             // cout << "NO LEAF" << endl;
    //             x = nil; // No children, so point to NULL
    //             transplant(z, x);
    //         }
    //         else if (z->left() == nil)
    //         {
    //             // cout << "RIGHT CHILD" << endl;
    //             x = z->right(); // No left child,so point to right
    //             transplant(z, x);
    //         }
    //         else if (z->right() == nil)
    //         {
    //             // cout << "LEFT CHILD" << endl;
    //             x = z->left(); // No right child,so point to left
    //             transplant(z, x);
    //         }
    //         else
    //         {
    //             y = z->right();
    //             while (y->left() != nil)
    //             {
    //                 y->decrementSize();
    //                 y = y->left();
    //             }
    //             was_y_red = y->isRed();
    //             x = y->right(); // Now y is z's location.
    //             if (y->parent() == z)
    //             {
    //                 x->setParent(y);
    //             }
    //             else
    //             {
    //                 transplant(y, y->right());
    //                 y->setRight(z->right());
    //                 y->right()->setParent(y);
    //             }
    //             // y->setSize(z->size() - 1);
    //             transplant(z, y);
    //             y->setLeft(z->left());
    //             y->left()->setParent(y);
    //             y->setColor(z->getColor());
    //             y->setSize(z->getSize() - 1);
    //         }

    //         delete z;       // Deallocating memory after removing node
    //         if (!was_y_red) //
    //         {
    //             removeFixup(x);
    //         }
    //     }
    // }
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
    // void lowerBoundHelp(RBTNode<Key, E> *root, int &count, const Key &k) const
    // {
    //     if (root == nil or root->key() >= k)
    //     {
    //         return;
    //     }
    //     lowerBoundHelp(root->left(), count, k);
    //     if (root->key() < k)
    //         count++;
    //     lowerBoundHelp(root->right(), count, k);
    // }

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
    bool find(const Key &k) const
    {
        return findHelp(k) != nil;
    }
    int lowerBound(const Key &k) const
    {
        int count = 0;
        RBTNode<Key, E> *x = root;
        while (x != nil)
        {
            if (x->key() <= k)
            {
                count += x->getSize() - x->right()->getSize();
            }
            if (x->key() == k)
            {
                return count - 1;
            }
            else if (x->key() > k)
            {
                x = x->left();
            }
            else
            {
                x = x->right();
            }
        }
        return count;
    }

    void print() const
    {
        if (this->root == NULL)
            cout << "The Tree is empty";
        else
            printHelp(this->root);
        cout << endl;
    }
    // Preorder print
    void printHelp(RBTNode<Key, E> *root) const
    {
        if (root == nil) // Empty subtree, do nothing
            return;
        cout << root->element() << "->" << root->getSize() << "->" << (root->isRed() ? "RED" : "BLACK");
        ; // Print record

        if (root->left() == nil and root->right() == nil) // If it's leaf, no need to print its empty childs
            return;

        cout << '(';
        printHelp(root->left()); // Go left subtree
        cout << ')';

        cout << '(';
        printHelp(root->right()); // Go right subtree
        cout << ')';
    }
    template <typename Key_t, typename E_t>
    friend ostream &operator<<(ostream &os, RBT<Key_t, E_t> *t);
};
template <typename Key_t, typename E_t>
ostream &operator<<(ostream &os, RBT<Key_t, E_t> *t)
{
    if (t->root == t->nil)
        cout << "The Tree is empty";
    else
        t->printHelp(t->root);
    return os;
}
#endif
