#ifndef __PRIORITY_QUEUE__
#define __PRIORITY_QUEUE__
#include <iostream>
using namespace std;
// pq class
template <typename E, typename Key>
class PriorityQueue
{
protected:
    void operator=(const PriorityQueue &) {} // Protect assignment
    PriorityQueue(const PriorityQueue &) {}  // Protect copy constructor
public:
    PriorityQueue() {}
    virtual ~PriorityQueue() {}
    virtual void push(const E &, const Key &, int) = 0;
    virtual void pop() = 0;
    virtual const E &top() = 0;
    virtual bool empty() = 0;
    virtual size_t size() = 0;
    virtual void decreaseKey(int id, const Key &newKey) = 0;
    virtual bool isExist(int) = 0;
};
#endif