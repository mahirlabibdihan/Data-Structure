#ifndef __D_LINK__
#define __D_LINK__
// Doubly linked list node
#include "Link.hpp"
template <typename E>
class DLink : public Link<E>
{
public:
    Link<E> *prev; // Pointer to previous node
    // Constructors
    DLink(const E &it, Link<E> *prevp, Link<E> *nextp)
    {
        this->element = it;
        this->prev = prevp;
        this->next = nextp;
    }
    DLink(Link<E> *prevp = NULL, Link<E> *nextp = NULL)
    {
        this->prev = prevp;
        this->next = nextp;
    }
    void *operator new(size_t t)
    { // Overloaded new operator
        if (Link<E>::freelist == NULL)
            return ::new DLink<E>();       // Create space
        Link<E> *temp = Link<E>::freelist; // Can take from freelist
        Link<E>::freelist = Link<E>::freelist->next;
        return temp; // Return the link
    }
};
#endif