#ifndef __LINK__
#define __LINK__
#include <iostream>
using namespace std;
// Singly linked list node
/*template <typename T>
class Link
{
public:
    T value;
    Link *next;
    // Constructors
    Link(Link *nextval = NULL)
    {
        next = nextval;
    }
    Link(const T &value, Link *next = NULL)
    {
        this->value = value;
        this->next = next;
    }
};*/
// Singly linked list node with freelist support
template <typename E>
class Link
{
protected:
    static Link<E> *freelist; // Reference to freelist head
public:
    E element;     // Value for this node
    Link<E> *next; // Point to next node in list
    // Constructors
    Link() {}
    virtual ~Link() {}
    // Overloaded delete operator
    void operator delete(void *ptr)
    {
        ((Link<E> *)ptr)->next = freelist; // Put on freelist
        freelist = (Link<E> *)ptr;
    }
    static void clearFreeList()
    {
        while (freelist != NULL)
        {
            Link<E> *temp = freelist; // Can take from freelist
            freelist = freelist->next;
            ::delete temp;
        }
    }
};
// The freelist head pointer is actually created here
template <typename E>
Link<E> *Link<E>::freelist = NULL;
#endif