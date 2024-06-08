
#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *child[26] = {};
    bool isEndOfWord = false;
};

class Trie
{
    TrieNode *root;

    void insert(string key)
    {
        TrieNode *node = root;
        for (auto i : key)
        {
            if (node->child[i - 'a'] == NULL)
            {
                node->child[i - 'a'] = new TrieNode;
            }
            node = node->child[i - 'a'];
        }
        node->isEndOfWord = true;
    }

public:
    Trie(vector<string> words)
    {
        root = new TrieNode;
        for (auto word : words)
        {
            insert(word);
        }
    }
    int search(string key)
    {
        TrieNode *node = root;
        for (auto i : key)
        {
            if (node->child[i - 'a'] == NULL)
            {
                return false;
            }
            node = node->child[i - 'a'];
        }
        return node->isEndOfWord;
    }
};
void insert(TrieNode *root, string key)
{
    TrieNode *j = root;
    for (auto i : key)
    {
        if (j->child[i - 'a'] == NULL)
        {
            j->child[i - 'a'] = new TrieNode;
        }
        j = j->child[i - 'a'];
    }
    j->isEndOfWord = true;
}

int search(TrieNode *root, string key)
{
    TrieNode *j = root;
    for (auto i : key)
    {
        if (j->child[i - 'a'] == NULL)
        {
            return false;
        }
        j = j->child[i - 'a'];
    }
    return (j->isEndOfWord);
}

TrieNode *trie(long long n)
{
    TrieNode *root = new TrieNode;
    string x;
    while (n--)
    {
        cin >> x;
        insert(root, x);
    }
    return root;
}
