#ifndef __NODE__
#define __NODE__
#include <string>
using namespace std;
class Node
{
    string k;
    int v;
    Node *next_node;
    Node *prev_node;

public:
    Node()
    {
        k = "";
        v = -1;
        next_node = prev_node = nullptr;
    }
    Node(string k, int v, Node *n = nullptr, Node *p = nullptr)
    {
        this->k = k;
        this->v = v;
        next_node = n;
        prev_node = p;
    }
    string key() const { return k; }
    void setKey(string k) { this->k = k; }
    int value() const { return v; }
    void setValue(int v) { this->v = v; }
    Node *next() const { return next_node; }
    void setNext(Node *n) { next_node = n; }
    Node *prev() const { return prev_node; }
    void setPrev(Node *p) { prev_node = p; }
};
#endif