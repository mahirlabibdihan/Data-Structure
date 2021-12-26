#ifndef __STACK__
#define __STACK__
#include <iostream>
using namespace std;
#define Assert(val, s)                             \
    if (!(val))                                    \
    {                                              \
        cout << "Assertion Failed: " << s << endl; \
        exit(-1);                                  \
    }
// Stack abtract class
template <typename T>
class Stack
{
private:
    void operator=(const Stack &) {} // Protect assignment
    Stack(const Stack &) {}          // Protect copy constructor
public:
    Stack() {}          // Default constructor
    virtual ~Stack() {} // Base destructor
    // Reinitialize the stack. The user is responsible for
    // reclaiming the storage used by the stack elements.
    virtual void clear() = 0;
    // Push an element onto the top of the stack.
    // it: The element being pushed onto the stack.
    virtual void push(const T &it) = 0;
    // Remove the element at the top of the stack.
    // Return: The element at the top of the stack.
    virtual T pop() = 0;
    // Return: The number of elements in the stack.
    virtual int length() const = 0;
    // Return: A copy of the top element.
    virtual const T &topValue() const = 0;
    virtual void setDirection(int direction) = 0;
};
template <typename T>
ostream &operator<<(ostream &os, Stack<T> *s)
{
    /*Stack<T> *tmp = new LStack<T>(s->length());
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
    delete tmp;*/
    return os;
}
#endif