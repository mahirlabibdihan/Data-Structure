#ifndef __S_LINK__
#define __S_LINK__
#include <cstddef>
// Singly linked list node
#include "Link.hpp"
template <typename E>
class SLink : public Link<E>
{
public:
    // Constructors
    SLink(Link<E> *nextp = NULL) { this->next = nextp; }
    SLink(const E &it, Link<E> *nextp = NULL)
    {
        this->element = it;
        this->next = nextp;
    }
    void *operator new(size_t t)
    { // Overloaded new operator
        if (Link<E>::freelist == NULL)
            return ::new SLink<E>();       // Create space
        Link<E> *temp = Link<E>::freelist; // Can take from freelist
        Link<E>::freelist = Link<E>::freelist->next;
        return temp; // Return the link
    }
};
#endif