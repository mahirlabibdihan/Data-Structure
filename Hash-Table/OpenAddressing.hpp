#ifndef __OPEN_ADDRESSING__
#define __OPEN_ADDRESSING__
#include "HashTable.hpp"
#include "Pair.hpp"
class OpenAddressing : public HashTable
{
    vector<Pair> table;
    const int c1 = 5, c2 = 13;

public:
    OpenAddressing(const int sz, hash_type type) : table(sz, Pair()), HashTable(sz, type)
    {
    }
    uint64_t hash(string &k, uint64_t i)
    {
        switch (type)
        {
        case QUADRATIC_PROBING:
        {
            return (hash1(k) + c1 * i + c2 * i * i) % table_size;
        }
        break;
        case LINEAR_PROBING:
        {
            return (hash1(k) + i) % table_size;
        }
        break;
        case DOUBLE_HASHING:
        {
            return (hash1(k) + i * hash2(k, table_size)) % table_size;
        }
        break;
        default:
            return -1;
            break;
        }
    }
    void insert(string &k, const int v)
    {
        Pair new_pair = Pair(k, v);
        for (uint64_t i = 0; i < table_size; i++)
        {
            int hash_index = hash(k, i) % table_size;
            // Assert(hash_index != -1, "NO HASH VALUE FOUND");
            if (table[hash_index].value() == -1)
            {
                table[hash_index] = new_pair;
                visited[hash_index] = true;
                return;
            }
            else if (table[hash_index].key() == k)
            {
                // Assert(false, "Already exists " + to_string(hash2(k)));
                table[hash_index] = new_pair;
                return;
            }
        }
        // Assert(false, "Couldn't insert " + to_string(hash2(k, table_size)) + " " + to_string(table_size));
    }
    int search(string &k)
    {
        for (uint64_t i = 0; i < table_size; i++)
        {
            int hash_index = hash(k, i) % table_size;
            // Assert(hash_index != -1, "NO HASH VALUE FOUND");
            if (table[hash_index].value() == -1 && !visited[hash_index])
            {
                return -1;
            }
            else if (table[hash_index].value() != -1 && table[hash_index].key() == k)
            {
                return table[hash_index].value();
            }
            prob_count++;
        }
        return -1;
    }
    void remove(string &k)
    {
        for (uint64_t i = 0; i < table_size; i++)
        {
            int hash_index = hash(k, i) % table_size;
            // Assert(hash_index != -1, "NO HASH VALUE FOUND");
            // Assert(!(table[hash_index].value() == -1 && !visited[hash_index]), "No such key to delete " + k);
            if (table[hash_index].value() != -1 && table[hash_index].key() == k)
            {
                table[hash_index].setValue(-1);
                break;
            }
        }
    }
};
#endif