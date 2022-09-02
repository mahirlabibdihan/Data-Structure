#include "HashTable.hpp"
#include "Node.hpp"

class ClosedAddressing : public HashTable
{
    vector<Node *> table;

public:
    ClosedAddressing(const int sz, hash_type type) : table(sz, nullptr), HashTable(sz, type)
    {
    }
    int search(string &k)
    {
        int hash_index = hash1(k) % table_size;
        Node *curr = table[hash_index];
        while (curr != nullptr)
        {
            if (curr->key() == k)
            {
                return curr->value();
            }
            curr = curr->next();
            this->prob_count++;
        }
        return -1;
    }
    void insert(string &k, const int v)
    {
        int hash_index = hash1(k) % table_size;
        Node *new_node = new Node(k, v);
        Node *head = table[hash_index];
        table[hash_index] = new_node;
        new_node->setNext(head);
        if (head != nullptr)
        {
            head->setPrev(new_node);
        }
    }
    void remove(string &k)
    {
        int hash_index = hash1(k) % table_size;
        Node *curr = table[hash_index];
        while (curr != nullptr)
        {
            if (curr->key() == k)
            {
                // 1st node
                if (curr == table[hash_index])
                {
                    table[hash_index] = curr->next();
                }
                if (curr->next() != nullptr)
                {
                    curr->next()->setPrev(curr->prev());
                }
                if (curr->prev() != nullptr)
                {
                    curr->prev()->setNext(curr->next());
                }
                delete curr;
                break;
            }
            curr = curr->next();
            // Assert(curr != nullptr, "Delete: No such key " + k);
        }
    }
};