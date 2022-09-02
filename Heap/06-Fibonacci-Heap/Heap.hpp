#ifndef __HEAP__
#define __HEAP__
#include <iostream>
#include "HeapNode.hpp"
using namespace std;
#define Assert(val, s)                             \
    if (!(val))                                    \
    {                                              \
        cout << "Assertion Failed: " << s << endl; \
        exit(-1);                                  \
    }
// heap class
template <typename E, typename Key>
class Heap
{
protected:
    void operator=(const Heap &) {} // Protect assignment
    Heap(const Heap &) {}           // Protect copy constructor
public:
    Heap() {}
    virtual ~Heap() {}
    virtual int size() const = 0; // Return current heap size
    // Insert "it" into the heap
    virtual void insert(const E &it, const Key &k, int) = 0;
    // Remove first value
    virtual E extractMin() = 0;
    virtual const E &getMin() = 0;
};
#endif