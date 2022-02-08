#ifndef __DSU__
#define __DSU__
// General tree representation for UNION/FIND
class DSU
{
private:
    int *parent;             // Node array
    int size;                // Size of node array
    int find(int curr) const // Find root
    {
        // Find root
        while (parent[curr] != -1)
            curr = parent[curr];
        return curr; // At root
    }

public:
    DSU(int n) // Constructor
    {
        size = n;
        parent = new int[size];
        for (int i = 0; i < size; i++)
        {
            parent[i] = -1;
        }
    }
    ~DSU() { delete[] parent; } // Destructor
    void unite(int, int)        // Merge equivalences
    {
        int s1 = find(u);
        int s2 = find(v);
        if (s1 != s2)
        {
            parent[s2] = s1;
        }
    }
    bool differ(int, int) // True if not in same tree
    {
        return find(u) != find(v);
    }
};
#endif