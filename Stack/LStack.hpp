#ifndef __L_STACK__
#define __L_STACK__
#include <iostream>
#include "Stack.hpp"
#include "../Link/SLink.hpp"
using namespace std;
// Linked stack implementation
template <typename E>
class LStack : public Stack<E>
{
private:
    Link<E> *top; // Pointer to first element
    int size;     // Number of elements
    void init()
    {
        top = NULL;
        size = 0;
    }

public:
    LStack(int size = 0) // Constructor
    {
        init();
    }
    ~LStack() { clear(); } // Destructor
    void clear()
    { // Reinitialize
        while (top != NULL)
        { // Delete link nodes
            Link<E> *temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
    }
    void push(const E &it)
    { // Put "it" on stack
        top = new SLink<E>(it, top);
        size++;
    }
    E pop()
    { // Remove "it" from stack
        Assert(top != NULL, "Stack is empty");
        E it = top->element;
        Link<E> *ltemp = top->next;
        delete top;
        top = ltemp;
        size--;
        return it;
    }
    const E &topValue() const
    { // Return top value
        Assert(top != 0, "Stack is empty");
        return top->element;
    }
    int length() const { return size; } // Return length
    void setDirection(int direction)
    {
    }
};
#ifndef __STACK_PRINT__
#define __STACK_PRINT__
template <typename T>
ostream &operator<<(ostream &os, Stack<T> *s)
{
    Stack<T> *tmp = new LStack<T>(s->length());
    os << "<";
    while (s->length() > 0)
    {
        tmp->push(s->topValue());
        s->pop();
    }
    while (tmp->length() > 0)
    {
        os << tmp->topValue();
        s->push(tmp->topValue());
        tmp->pop();
        if (tmp->length() > 0)
        {
            os << ", ";
        }
    }
    cout << ">";
    delete tmp;
    return os;
}
#endif
#endif