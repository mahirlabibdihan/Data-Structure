
#ifndef __HASH_TABLE__
#define __HASH_TABLE__
#include <vector>
#include <string>
#include <iostream>
#include "HashFunction.hpp"
using namespace std;
enum hash_type
{
    SEPARATE_CHAINING,
    LINEAR_PROBING,
    QUADRATIC_PROBING,
    DOUBLE_HASHING
};
#define Assert(val, s)                             \
    if (!(val))                                    \
    {                                              \
        cout << "Assertion Failed: " << s << endl; \
        exit(-1);                                  \
    }

class HashTable
{
protected:
    int table_size;
    int prob_count;
    vector<bool> visited;
    hash_type type;

public:
    HashTable(const int sz, hash_type t) : visited(sz, false)
    {
        table_size = sz;
        type = t;
        prob_count = 0;
    }
    int getProbCount()
    {
        return prob_count;
    }
    void resetProbCount()
    {
        prob_count = 0;
    }
    virtual int search(string &k) = 0;
    virtual void insert(string &k, const int v) = 0;
    virtual void remove(string &k) = 0;
};
#endif