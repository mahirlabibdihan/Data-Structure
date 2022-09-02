#ifndef __CLOSED_ADDRESSING__
#define __CLOSED_ADDRESSING__
#include "HashTable.hpp"
#include "Node.hpp"
#include "RBT/RBT.hpp"

class ClosedAddressing : public HashTable
{
    vector<RBT<string, int>> table;

public:
    ClosedAddressing(const int sz, hash_type type) : table(sz, RBT<string, int>()), HashTable(sz, type)
    {
    }
    int search(string &k)
    {
        int hash_index = hash1(k) % table_size;
        return table[hash_index].find(k);
    }
    void insert(string &k, const int v)
    {
        int hash_index = hash1(k) % table_size;
        if (this->search(k) != -1)
            this->remove(k);
        table[hash_index].insert(k, v);
    }
    void remove(string &k)
    {
        int hash_index = hash1(k) % table_size;
        // Assert(table[hash_index].remove(k), "No such key");
    }
};
#endif